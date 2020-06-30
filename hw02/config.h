#ifndef HW02_CONFIG_H
#define HW02_CONFIG_H

/**
 * Struct pair identifies one pair in a section.
 * The pair is defined by its @key and @value.
 */
struct pair {
	char *key;
	char *value;
};

/**
 * Struct section represents one section.
 * It holds its @name and an array of @pairs.
 * The attribute @allocated defines how many pairs are allocated in the pairs array.
 * the attribute @size defines how many pairs the array contains.
 */
struct section {
	char *name;
	struct pair *pairs;
	unsigned int allocated;
	unsigned int size;
};

/**
 * Struct config represents one parsed config file.
 * It holds an array of @sections.
 * The attribute @allocated defines how many sections are allocated in array sections.
 * The attribute @size defines how many sections the array contains.
 * The attribute @ignoreSection indicates if the currently processed section should be ignored.
 * The attribute @wasFirstSection indicates if a section has been already read.
 */
struct config {
	struct section *sections;
	unsigned int allocated;
	unsigned int size;
	unsigned short int ignoreSection;
	unsigned short int wasFirstSection;
};

/**
 * Inits the config structure
 *
 * @param cfg The config structure.
 */
void configInit(struct config *cfg);

/**
 * Reads the config file.
 *
 * @param cfg The config structure.
 * @param name The path to the config file.
 * @return 0 in case of success
 *         1 in case the file cannot be opened
 *         2 in case the format of the config file is wrong
 *         3 in case of bad allocation
 */
int configRead(struct config *cfg, const char *name);

/**
 * Get the config value
 *
 * @param cfg The config structure.
 * @param section The section of the config file.
 * @param key The key of the section of the config file.
 * @param type The type of the value.
 * @param value The output parameter for loading value.
 * @param length The length of the provided buffer for value
 * @return 0 in case of success
 *         1 in case the section name is not found
 *         2 in case the key is not found
 *         3 in case the key is too long for provided buffer
 */
int configValue(const struct config *cfg,
    const char *section,
    const char *key,
    char *value,
    int length);

/**
 * Release all resources held by the config structure.
 *
 * @param cfg The config structure.
 */
void configClean(struct config *cfg);

#endif // HW02_CONFIG_H
