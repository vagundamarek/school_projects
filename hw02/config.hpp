#ifndef HW02_CONFIG_HPP
#define HW02_CONFIG_HPP

#include <iostream>
#include <set>
#include <string>
#include <vector>

enum class Status {
    Success,
    MissingSection,
    MissingKey,
    FileNotFound,
    WrongFormat
};

class Key {
public:
    std::string name;
    std::set<std::string> values;
    Key(const std::string& n)
        : name(n)
        , values()
    {
    }
};

class Section {
public:
    std::string name;
    std::vector<Key> keys;
    friend inline bool operator<(const Section& lhs, const Section& rhs)
    {
        return lhs.name.compare(rhs.name) < 0;
    }
    Section(const std::string& n)
        : name(n)
        , keys(){};
};
class Config {
private:
    //std::string filename;
    std::vector<Section> sections;
    Status status;
    const Key* getKey(const std::string& secName, const std::string& keyName) const;
    Key* getKey(const std::string& secName, const std::string& keyName);
    const Section* getSection(const std::string& secName) const;
    Section* getSection(const std::string& secName);

public:
    /** Read the config file.
	 *
	 *  @param name The path to the config file.
	 *  @return Success in case of success
	 *          FileNotFound in case the file cannot be opened (does not matter why)
	 *          WrongFormat in case the format of the config file is wrong
	 */
    Status read(const std::string& name);

    /** Get the config value.
	 *
	 *  @param secName The section of the config file.
	 *  @param keyName The key of the section of the config file.
	 *  @return {Success, value} in case of success
	 *          {MissingSection, empty string} in case the section name is not found
	 *          {MissingKey, empty string} in case the key is not found
	 *
	 * (Note: this function's prototype is going to change in the desired
	 *  extension. You may want to change the docstring accordingly.)
	 */
    std::pair<Status, std::set<std::string>> value(const std::string& secName, const std::string& keyName) const;

    /** Find out whether the config file contains a section with the given name.
	 *
	 *  @param secName The section of the config file.
	 *  @return true if contains, false otherwise
	 */
    bool hasSection(const std::string& secName) const;

    /** Find out whether the config file contains a key with the given name
         *  in the particular section.
	 *
	 *  @param secName The section of the config file.
	 *  @param keyName The key of the section of the config file.
	 *  @return true if contains, false otherwise
	 */
    bool hasKey(const std::string& secName, const std::string& keyName) const;

    /** Find out whether the given key of the given section has the provided value.
	 *
	 *  @param secName The section of the config file.
	 *  @param keyName The key of the section of the config file.
	 *  @param value The tested value.
	 *  @return true if the key can have only this value, false otherwise
	 */
    bool isValue(const std::string& secName, const std::string& keyName, const std::string& value) const;

    /** Find out whether the given key of given section can have provided value.
	 *
	 *  @param secName The section of the config file.
	 *  @param keyName The key of the section of the config file.
	 *  @param value The tested value.
	 *  @return true if the key can have the value, false otherwise
	 */
    bool hasValue(const std::string& secName, const std::string& keyName, const std::string& value) const;

    /** Prints out the current structure of the config file.
	 *
	 *  @param name The path to the output file.
	 *  @return Success in case of success
	 *          FileNotFound in case the file cannot be opened
	 */
    Status serialize(const std::string& fileName) const;
};

#endif // HW02_CONFIG_HPP
