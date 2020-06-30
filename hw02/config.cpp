#include "config.hpp"
#include <fstream>

bool isBlankStr(const std::string& str)
{
    for (auto& x : str) {
        if (!isspace(x))
            return false;
    }
    return true;
}

bool ignore(const std::string& str)
{
    return (str[0] == ';' || isBlankStr(str));
}

bool isValidKey(const std::string& str)
{
    if (str.find_first_of('=') == std::string::npos)
        return false;
    size_t bracket = str.find_first_of("[");
    if (bracket != std::string::npos) {
        if (str.find_first_not_of(" \t\v\f\r", 0, bracket) == std::string::npos)
            return false;
    }
    size_t equalsPos = str.find_first_of('=');
    if (isBlankStr({ str, 0, equalsPos }) || isBlankStr({ str, equalsPos + 1, str.length() - equalsPos }) || !equalsPos)
        return false;
    size_t orPos_1 = str.find_first_of('|');
    if (orPos_1 < equalsPos)
        return false;
    if (orPos_1 != std::string::npos && str.find_first_not_of(" \t\v\f\r", equalsPos + 1, orPos_1 - equalsPos - 1) == std::string::npos)
        return false;
    size_t orPos_2 = str.find_first_of('|', orPos_1 + 1);
    while (orPos_2 != std::string::npos) {
        if (str.find_first_not_of(" \t\v\f\r", orPos_1 + 1, orPos_2 - orPos_1 - 1) == std::string::npos)
            return false;
        orPos_1 = orPos_2;
        orPos_2 = str.find_first_of('|', orPos_1 + 1);
    }
    return !(orPos_1 != std::string::npos && str.find_first_not_of(" \t\v\f\r", orPos_1 + 1) == std::string::npos);
}

std::vector<std::string> parseKey(const std::string& str)
{

    std::vector<std::string> parts;
    //left side of =
    size_t begin = str.find_first_not_of(" \t\v\f\r");
    size_t separator_1 = str.find_first_of('=');
    size_t end = str.find_last_not_of(" \t\v\f\r", separator_1 - 1);
    parts.emplace_back(str, begin, end - begin + 1);
    //right side of =
    begin = str.find_first_not_of(" \t\v\f\r", separator_1 + 1);
    separator_1 = str.find_first_of('|', separator_1 + 1);
    if (separator_1 == std::string::npos)
        end = str.find_last_not_of(" \t\v\f\r");
    else
        end = str.find_last_not_of(" \t\v\f\r", separator_1 - 1);
    parts.emplace_back(str, begin, end - begin + 1);

    //or sections
    size_t separator_2 = str.find_first_of('|', separator_1 + 1);
    while (separator_1 != std::string::npos) {
        begin = str.find_first_not_of(" \t\v\f\r", separator_1 + 1);
        if (separator_2 != std::string::npos)
            end = str.find_last_not_of(" \t\v\f\r", separator_2 - 1);
        else
            end = str.find_last_not_of(" \t\v\f\r");
        parts.emplace_back(str, begin, end - begin + 1);
        separator_1 = separator_2;
        separator_2 = str.find_first_of('|', separator_1 + 1);
    }
    return parts;
}
std::string parseSectionName(const std::string& str)
{
    size_t open = str.find_first_of('[');
    size_t close = str.find_first_of(']');
    if (open == std::string::npos || close == std::string::npos)
        return "";
    if (open + 1 > close)
        return "";
    //if (str.find_first_not_of(" \t\v\f\r", open+1, close - open-1) == std::string::npos)
    //   return "";
    size_t first = str.find_first_not_of(" \t\v\f\r", open + 1);
    size_t last = str.find_last_not_of(" \t\v\f\r", close - 1);
    if (first == std::string::npos || last == std::string::npos || last < first)
        return "";
    std::string out(str, first, last - first + 1);
    return out;
}

Status Config::read(const std::string& name)
{
    std::ifstream file(name);
    if (!file.is_open()) {
        std::cerr << "Unable to open provided file " << name << std::endl;
        status = Status::FileNotFound;
        return status;
    }
    status = Status::WrongFormat;
    std::string line;
    std::string currentSectionName;
    bool skip = false;
    while (!file.eof()) {
        std::getline(file, line);
        if (ignore(line))
            continue;
        if (line.find_first_of("[") != std::string::npos) {
            //section load
            skip = false;
            currentSectionName = parseSectionName(line);
            if (currentSectionName.empty())
                return status;

            if (hasSection(currentSectionName)) {
                std::cerr << "Attempt to add already existing section " << currentSectionName << " ignored" << std::endl;
                skip = true;
            } else
                sections.emplace_back(currentSectionName);
        }

        else {
            //key load
            if (currentSectionName.empty())
                return status;
            if (!isValidKey(line))
                return status;
            if (skip)
                continue;
            std::vector<std::string> parts = parseKey(line);
            Section* current = getSection(currentSectionName);
            Key* key = getKey(current->name, parts[0]);
            if (!key) {
                Key newKey(parts[0]);
                current->keys.emplace_back(newKey);
                key = getKey(current->name, parts[0]);
            }
            parts.erase(parts.begin());
            for (auto& x : parts) {
                if (!key->values.emplace(x).second)
                    std::cerr << "Attempt to add already existing key " << key->name << " into section " << current->name << " ignored" << std::endl;
            }
        }
    }
    status = Status::Success;
    file.close();
    return status;
}

std::pair<Status, std::set<std::string>> Config::value(const std::string& secName, const std::string& keyName) const
{
    if (!hasSection(secName))
        return { Status::MissingSection, {} };
    const Key* k = getKey(secName, keyName);
    if (!k)
        return { Status::MissingKey, {} };
    return { Status::Success, k->values };
}

bool Config::hasSection(const std::string& secName) const
{
    return getSection(secName) != nullptr;
}

const Key* Config::getKey(const std::string& secName, const std::string& keyName) const
{
    /*
    for (auto& x : sections) {
        if (x.name == secName)
            for (auto& y : x.keys) {
                if (y.name == keyName)
                    return std::addressof(y);
            }
    }*/
    for (auto x = sections.begin(); x != sections.end(); x++) {
        if (x->name == secName) {
            for (auto y = x->keys.begin(); y != x->keys.end(); y++)
                if (y->name == keyName)
                    return &(*y);
        }
    }

    return nullptr;
}

Key* Config::getKey(const std::string& secName, const std::string& keyName)
{
    return const_cast<Key*>(static_cast<const Config&>(*this).getKey(secName, keyName));
}

const Section* Config::getSection(const std::string& secName) const
{
    /*
    for (auto& x : sections) {
        if (x.name == secName)
            return std::addressof(x);
    }*/

    for (auto x = sections.begin(); x != sections.end(); x++) {
        if (x->name == secName)
            return &(*x);
    }
    return nullptr;
}

Section* Config::getSection(const std::string& secName)
{
    return const_cast<Section*>(static_cast<const Config&>(*this).getSection(secName));
}
bool Config::hasKey(const std::string& secName, const std::string& keyName) const
{
    return getKey(secName, keyName) != nullptr;
}

bool Config::isValue(const std::string& secName, const std::string& keyName, const std::string& value) const
{
    const Key* k = getKey(secName, keyName);
    if (!k)
        return false;
    return k->values.find(value) != k->values.end() && k->values.size() == 1;
}

bool Config::hasValue(const std::string& secName, const std::string& keyName, const std::string& value) const
{
    const Key* k = getKey(secName, keyName);
    if (!k)
        return false;
    return k->values.find(value) != k->values.end();
}

Status Config::serialize(const std::string& fileName) const
{
    std::ofstream file(fileName);
    if (!file.is_open())
        return Status::FileNotFound;
    for (auto& x : sections) {
        file << '[' << x.name << ']' << std::endl;
        for (auto& y : x.keys) {
            for (auto& z : y.values)
                file << y.name << '=' << z << std::endl;
        }
    }
    file.close();
    return Status::Success;
}
