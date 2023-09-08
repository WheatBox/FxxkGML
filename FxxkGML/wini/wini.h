#pragma once

#include <unordered_map>
#include <string>

namespace wini {

enum class ERROR {
	OK = 0, // 没得任何问题
	READ_FILE_FAILED___USING_DEFAULTS, // 读取文件失败，将会使用默认配置
	WRITE_FILE_FAILED, // 写入文件失败
};

class value {
public:
	value() = default;
	value(bool val);
	value(int val);
	value(double val);
	value(const char * val);
	value(const std::string & val);

	void setbool(bool val);
	void setint(int val);
	void setdouble(double val);
	void setstring(const char * val);
	void setstring(const std::string & val);

	bool getbool();
	int getint();
	double getdouble();
	std::string getstring();

private:
	std::string m_str;
};

using section_t = std::unordered_map<std::string, value>;

class wini {
public:
	wini() = default;

	ERROR load(const std::string & filename);

	ERROR save(const std::string & filename);
	ERROR save();

private:
	std::string m_filename;

private:
	value * getvalue(const std::string & section, const std::string & key, bool create_if_null = false);

	void setdirctly(const std::string & section, const std::string & key, const std::string & val);

public:

	/* 比较精确的 */
	bool getbool(const std::string & section, const std::string & key, bool _default);
	int getint(const std::string & section, const std::string & key, int _default);
	double getdouble(const std::string & section, const std::string & key, double _default);
	std::string getstring(const std::string & section, const std::string & key, const char * _default);
	std::string getstring(const std::string & section, const std::string & key, const std::string & _default);

	void setbool(const std::string & section, const std::string & key, bool val);
	void setint(const std::string & section, const std::string & key, int val);
	void setdouble(const std::string & section, const std::string & key, double val);
	void setstring(const std::string & section, const std::string & key, const char * val);
	void setstring(const std::string & section, const std::string & key, const std::string & val);
	/* --------- */
	
	/* 比较灵活的 */
	bool get(const std::string & section, const std::string & key, bool _default);
	int get(const std::string & section, const std::string & key, int _default);
	double get(const std::string & section, const std::string & key, double _default);
	std::string get(const std::string & section, const std::string & key, const char * _default);
	std::string get(const std::string & section, const std::string & key, const std::string & _default);

	void set(const std::string & section, const std::string & key, bool val);
	void set(const std::string & section, const std::string & key, int val);
	void set(const std::string & section, const std::string & key, double val);
	void set(const std::string & section, const std::string & key, const char * val);
	void set(const std::string & section, const std::string & key, const std::string & val);
	/* --------- */

private:
	std::unordered_map<std::string, section_t> m_sections;

};

};
