#include "config.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Initializes a pair with the provided @key and @value.
 * Expects already valid inputs.
 * @return 0 in case of success
 *         1 in case allocation fails
 */
static int pairInit(struct pair *pair, const char *key, const char *value) {
	pair->key = malloc(strlen(key) + 1);
	if (pair->key == NULL) {
		return 1;
	}
	memcpy(pair->key, key, strlen(key) + 1);
	pair->value = malloc(strlen(value) + 1);
	if (pair->value == NULL) {
		free(pair->key);
		return 1;
	}
	memcpy(pair->value, value, strlen(value) + 1);
	return 0;
}

/**
 * Cleans a pair - frees all resources held by a section.
 */
static void pairClean(struct pair *pair) {
	if (pair == NULL)
		return;
	if (pair->key != NULL) {
        puts(pair->key);
		free(pair->key);
		pair->key = NULL;
	}
	if (pair->value != NULL) {
        puts(pair->value);
		free(pair->value);
		pair->value = NULL;
	}
}

/**
 * Initializes a section with the provided @name. Expects a valid name.
 * @return 0 in case of success
 *         1 in case allocation fails
 */
static int sectionInit(struct section *sec, const char *name) {
	sec->size = 0;
	sec->allocated = 0;

	sec->name = malloc(strlen(name) + 1);
	if (sec->name == NULL) {
		return 1;
	}

	sec->pairs = NULL;
	sec->allocated = 0;
	sec->size = 0;
	return 0;
}

/**
 * Expands a section. The new size will be the original one multiplied by 2.
 * @return 0 in case of success
 *         1 in case allocation fails
*/
static int expandSection(struct section *sec) {
	unsigned int nextSize = sec->allocated ? sec->allocated << 1 : 1;
	struct pair *reallocated = realloc(sec->pairs, nextSize * sizeof(struct pair));
	if (reallocated == NULL) {
		return 1;
	}

	sec->pairs = reallocated;
	sec->allocated = nextSize;
	return 0;
}

/**
 * Frees all resources held by a section.
 */
static void sectionClean(struct section *sec) {
	if (sec->name != NULL) {
        puts(sec->name);
		free(sec->name);
		sec->name = NULL;
	}

	// section is already clean
	if (sec->pairs == NULL)
		return;

	// clean pairs
	for (unsigned int i = 0; i < sec->size; ++i) {
		pairClean(&sec->pairs[i]);
	}
	sec->size = 0;

	// deallocate memory
	free(sec->pairs);
	sec->pairs = NULL;
	sec->allocated = 0;
}

void configInit(struct config *cfg) {
	cfg->allocated = 0;
	cfg->size = 0;
	cfg->sections = NULL;
	cfg->ignoreSection = 0;
	cfg->wasFirstSection = 0;
}

/**
 * Expands a config. The new size will be the original one multiplied by 2.
 * @return 0 in case of success
 *         1 in case allocation fails
 */
static int expandConfig(struct config *cfg) {
	unsigned int nextSize = cfg->allocated ? cfg->allocated << 1 : 1;
	struct section *reallocated = realloc(cfg->sections, nextSize * sizeof(struct section));
	if (reallocated == NULL) {
		return 1;
	}

	cfg->sections = reallocated;
	cfg->allocated = nextSize;
	return 0;
}

void configClean(struct config *cfg) {
	// config is already clean
	if (cfg->sections == NULL)
		return;

	// clean sections
	for (unsigned int i = 0; i < cfg->size; ++i) {
		sectionClean(&cfg->sections[i]);
	}
	cfg->size = 0;

	// deallocate memory
	free(cfg->sections);
	cfg->sections = NULL;
	cfg->allocated = 0;
	cfg->ignoreSection = 0;
	cfg->wasFirstSection = 0;
}

/**
 * Looks whether the given section @name already exists.
 */
static int sectionExists(struct config *cfg, const char *name) {
	for (unsigned int i = 0; i < cfg->size; ++i) {
		if (strcmp(name, cfg->sections[i].name) == 0) {
			return 1;
		}
	}
	return 0;
}

/**
 * Looks for duplicate keys with the name @key in the provided section @sec.
 */
static int keyExists(struct section *sec, const char *key) {
	for (unsigned int i = 0; i < sec->size; ++i) {
		if (strcmp(key, sec->pairs[i].key) == 0) {
			return 1;
		}
	}
	return 0;
}

/**
 * Adds a new section with @name into the config structure @cfg.
 * Checks for duplicities.
 */
static int addSection(const char *name, struct config *cfg) {
	if (sectionExists(cfg, name)) {
		fprintf(stderr, "Attempt to add already existing section %s ignored\n", name);
		cfg->ignoreSection = 1;
		return 0;
	}

	cfg->ignoreSection = 0;
	if (cfg->allocated == cfg->size) {
		if (expandConfig(cfg)) {
			// fail during reallocation
			return 1;
		}
	}

	struct section *mySection = &cfg->sections[cfg->size];
	if (sectionInit(mySection, name)) {
		// fail during reallocation
		return 1;
	}
	++cfg->size;
	return 0;
}

/**
 * Adds a pair with @key and @value into the last section held by config @cfg.
 * Checks for duplicities. Checks if current section should be ignored.
 */
static int addPair(const char *key, const char *value, struct config *cfg) {
	if (cfg->ignoreSection) {
		return 0;
	}

	struct section *sec = &cfg->sections[cfg->size - 1];

	if (keyExists(sec, key)) {
		fprintf(stderr, "Attempt to add already existing key %s into section %s ignored\n", key, sec->name);
		return 0;
	}

	if (sec->allocated == sec->size) {
		if (expandSection(sec)) {
			// fail during reallocation
			return 1;
		}
	}

	struct pair *myPair = &sec->pairs[sec->size];
	if (pairInit(myPair, key, value)) {
		// fail during reallocation
		return 1;
	}
	++sec->size;
	return 0;
}

static char *ignoreSpaces(char *line) {
	while (isspace(*line))
		++line;

	return line;
}

static void removeSpacesFromBack(const char *line, char *lineEnd) {
	while (isspace(*lineEnd) && lineEnd != line) {
		*lineEnd = 0;
		--lineEnd;
	}
}

static int isSection(const char *line) {
	return line[0] == '[';
}

static int isValid(const char *value) {
	return strlen(value) != 0;
}

/*
 * Function for reading one line from provided opened FILE.
 * Ignores comment lines and empty lines.
 * Does not manage the release of the allocated line.
 * @param file - to read from
 * @param line - buffer for reading
 * @param length - indicating the allocated length of buffer
 * @return how much read, -1 if allocation fails
*/
static int readLine(FILE *file, char *line, int *length) {
	memset(line, 0, *length);
	const int inc = 1024;

	char c = getc(file); // check comment and empty line

	while (c == '\n' || c == ';') {
		if (c == ';') {
			// read comment till the end of line
			for (c = getc(file); c != '\n' && c != EOF; c = getc(file)) {
			}
		}
		c = getc(file);
	}

	if (c == EOF) {
		return 0;
	}

	line[0] = c;
	int i = 1; // position in the buffer, first char has already been read

	for (c = getc(file); c != '\n' && c != EOF; c = getc(file)) {
		if (*length <= i) {
			*length += inc;
			char *tmp = (char *)realloc(line, *length);
			if (tmp == NULL) {
				return -1;
			}
			line = tmp;
		}
		line[i] = c;
		++i;
	}
	return i;
}

/**
 * Parses the @line into section/pair and eventually inserts it into the
 * config @cfg. Param @length indicates how long the buffer is.
 * @return 0 in case of success
 *         2 in case the parsing fails
 *         3 in case allocation fails
 */
static int parseLine(char *line, unsigned int length, struct config *cfg) {
	line = ignoreSpaces(line); // ignore initial white spaces

	if (strlen(line) == 0) {
		// just an empty line
		return 0;
	}

	if (isSection(line)) {
		const char *name = ignoreSpaces(line + 1);
		char *ending = strchr(name, ']');

		if (ending == NULL) {
			return 2;
		}

		*ending = 0;
		removeSpacesFromBack(name, ending - 1);

		if (!isValid(name)) {
			return 2;
		}

		if (addSection(name, cfg)) {
			return 3;
		}

		cfg->wasFirstSection = 1;
	} else {
		char *key = ignoreSpaces(line);
		char *middle = strchr(line, '=');

		if (middle == NULL || cfg->wasFirstSection == 0) {
			return 2;
		}

		*middle = 0;
		char *value = middle + 1;
		value = ignoreSpaces(value);

		removeSpacesFromBack(key, middle - 1);
		removeSpacesFromBack(value, line + length - 1);

		if (!isValid(key) || !isValid(value)) {
			return 2;
		}

		if (addPair(key, value, cfg)) {
			return 3;
		}
	}
	return 0;
}

int configRead(struct config *cfg, const char *name) {
	char *buffer;
	int buffSize = 1024;
	buffer = malloc(buffSize);
	if (buffer == NULL) {
		return 3;
	}
	FILE *file = fopen(name, "rb");
	if (!file) {
		fprintf(stderr, "Unable to open provided file %s\n", name);
		return 1;
	}

	cfg->wasFirstSection = 0;

	int read;
	while ((read = readLine(file, buffer, &buffSize)) != 0) {
		if (read == -1) {
			// reallocation fails
			return 3;
		}
		int status = parseLine(buffer, read, cfg);
		if (status) {
			return status;
		}
	}

	// cleanup
	free(buffer);
	fclose(file);
	return 0;
}

int configValue(const struct config *cfg, const char *section, const char *key, char *value, int length) {
	for (unsigned int i = 0; i < cfg->size; ++i) {
		if (strcmp(section, cfg->sections[i].name) == 0) {
			struct section *sec = &cfg->sections[i];
			for (unsigned int i = 0; i < sec->size; ++i) {
				if (strcmp(key, sec->pairs[i].key) == 0) {
					if (strlen(sec->pairs[i].value) > length) {
						return 3;
					}
					strcpy(value, sec->pairs[i].value);
					return 0;
				}
			}
			return 2;
		}
	}
	return 1;
}
