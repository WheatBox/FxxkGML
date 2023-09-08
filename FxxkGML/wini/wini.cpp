#include "wini.h"

#include <fstream>

/* value */

wini::value::value(bool val) {
	setbool(val);
}

wini::value::value(int val) {
	setint(val);
}

wini::value::value(double val) {
	setdouble(val);
}

wini::value::value(const char * val) {
	setstring(val);
}

wini::value::value(const std::string & val) {
	setstring(val);
}

void wini::value::setbool(bool val) {
	m_str = (val ? "true" : "false");
}

void wini::value::setint(int val) {
	m_str = std::to_string(val);
}

void wini::value::setdouble(double val) {
	m_str = std::to_string(val);
}

void wini::value::setstring(const char * val) {
	m_str = val;
}

void wini::value::setstring(const std::string & val) {
	m_str = val;
}

bool wini::value::getbool() {
	return m_str != "false";
}

int wini::value::getint() {
	return std::stoi(m_str);
}

double wini::value::getdouble() {
	return std::stod(m_str);
}

std::string wini::value::getstring() {
	return m_str;
}

/* ----- */
/* wini */

wini::ERROR wini::wini::load(const std::string & filename) {
	m_filename = filename;
	m_sections.clear();

	std::fstream fs(filename, std::ios_base::in);
	if(!fs.is_open()) {
		return ERROR::READ_FILE_FAILED___USING_DEFAULTS;
	}

	std::string strsection = "";
	while(!fs.eof()) {
		std::string str;
		std::getline(fs, str);

		std::size_t i = 0;
		std::size_t len = str.length();

		std::string strkey = "";

		std::size_t equalspos = 0;
		std::string strtmp = "";
		for(; i < len; i++) {
			if(str[i] == ' ' || str[i] == '\t') {
				continue;
			}

			if(str[i] == ';' || str[i] == '#') {
				break; // 后头是注释，所以下一句
			}

			if(equalspos == 0 && str[i] == '[') {
				std::size_t j = ++i;
				for(; j < len; j++) {
					if(str[j] == ']')  {
						strsection = str.substr(i, j - i);
					}
				}
				break; // 当前行是 section，所以下一句
			}

			if(str[i] == '"' && strtmp.length() == 0) {
				std::size_t j = i + 1;
				std::size_t right = i;
				for(; j < len; j++) {
					if(str[j] == '"')  {
						right = j;
					}
				}
				if(i < right) {
					strtmp = str.substr(i, right - i + 1);
					i = j;
					continue;
				}
			}

			if(str[i] == '=') {
				if(strsection.length() == 0 || strkey.length() > 0) {
					break; // 没 section 信息，或者前面已经获取过 key 了，所以下一句
				}
				equalspos = i;
				strkey = strtmp;
				strtmp = "";
				continue;
			}

			strtmp += str[i];
		}

		if(i >= len && equalspos > 0 && strtmp.length() > 0) {
			setdirctly(strsection, strkey, strtmp);
		}
	}

	fs.close();
	return ERROR::OK;
}

wini::ERROR wini::wini::save(const std::string & filename) {
	std::fstream fs(filename, std::ios_base::out);
	if(!fs.is_open()) {
		return ERROR::WRITE_FILE_FAILED;
	}

	for(auto & secit : m_sections) {
		fs << "[" + secit.first + "]\n";
		
		for(auto & valit : secit.second) {
			fs << valit.first + "=" + valit.second.getstring() + "\n";
		}
	}

	fs.close();
	return ERROR::OK;
}

wini::ERROR wini::wini::save() {
	return save(m_filename);
}

wini::value * wini::wini::getvalue(const std::string & section, const std::string & key, bool create_if_null) {
	auto s = m_sections.find(section);
	if(s == m_sections.end()) {
		if(create_if_null) {
			m_sections[section] = section_t({{key, value()}});
			return &(m_sections[section][key]);
		} else {
			return nullptr;
		}
	}
	auto v = s->second.find(key);
	if(v == s->second.end()) {
		if(create_if_null) {
			return &(s->second[key] = value());
		} else {
			return nullptr;
		}
	}
	return &(v->second);
}

void wini::wini::setdirctly(const std::string & section, const std::string & key, const std::string & val) {
	getvalue(section, key, true)->setstring(val);
}

bool wini::wini::getbool(const std::string & section, const std::string & key, bool _default) {
	if(auto v = getvalue(section, key)) {
		return v->getbool();
	}
	return _default;
}
int wini::wini::getint(const std::string & section, const std::string & key, int _default) {
	if(auto v = getvalue(section, key)) {
		return v->getint();
	}
	return _default;
}
double wini::wini::getdouble(const std::string & section, const std::string & key, double _default) {
	if(auto v = getvalue(section, key)) {
		return v->getdouble();
	}
	return _default;
}
std::string wini::wini::getstring(const std::string & section, const std::string & key, const char * _default) {
	return getstring(section, key, std::string(_default));
}
std::string wini::wini::getstring(const std::string & section, const std::string & key, const std::string & _default) {
	if(auto v = getvalue(section, key)) {
		std::string strtmp = v->getstring();
		if(strtmp[0] == '"' && strtmp[strtmp.length() - 1] == '"') {
			return strtmp.substr(1, strtmp.length() - 2);
		}
		return strtmp;
	}
	return _default;
}

void wini::wini::setbool(const std::string & section, const std::string & key, bool val) {
	getvalue(section, key, true)->setbool(val);
}
void wini::wini::setint(const std::string & section, const std::string & key, int val) {
	getvalue(section, key, true)->setint(val);
}
void wini::wini::setdouble(const std::string & section, const std::string & key, double val) {
	getvalue(section, key, true)->setdouble(val);
}
void wini::wini::setstring(const std::string & section, const std::string & key, const char * val) {
	setstring(section, key, std::string(val));
}
void wini::wini::setstring(const std::string & section, const std::string & key, const std::string & val) {
	getvalue(section, key, true)->setstring("\"" + val + "\"");
}

bool wini::wini::get(const std::string & section, const std::string & key, bool _default) {
	return getbool(section, key, _default);
}
int wini::wini::get(const std::string & section, const std::string & key, int _default) {
	return getint(section, key, _default);
}
double wini::wini::get(const std::string & section, const std::string & key, double _default) {
	return getdouble(section, key, _default);
}
std::string wini::wini::get(const std::string & section, const std::string & key, const char * _default) {
	return getstring(section, key, std::string(_default));
}
std::string wini::wini::get(const std::string & section, const std::string & key, const std::string & _default) {
	return getstring(section, key, _default);
}

void wini::wini::set(const std::string & section, const std::string & key, bool val) {
	getvalue(section, key, true)->setbool(val);
}
void wini::wini::set(const std::string & section, const std::string & key, int val) {
	getvalue(section, key, true)->setint(val);
}
void wini::wini::set(const std::string & section, const std::string & key, double val) {
	getvalue(section, key, true)->setdouble(val);
}
void wini::wini::set(const std::string & section, const std::string & key, const char * val) {
	setstring(section, key, std::string(val));
}
void wini::wini::set(const std::string & section, const std::string & key, const std::string & val) {
	getvalue(section, key, true)->setstring("\"" + val + "\"");
}

/* ---- */
