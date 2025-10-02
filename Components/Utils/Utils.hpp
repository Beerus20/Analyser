#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <iostream>
# include <sstream>
class Utils
{
	private:
		Utils(void);
		Utils(const Utils &other);
		Utils	&operator=(const Utils &other);

	public:
		virtual ~Utils(void);

		static void			removeAll(std::string &to_change, const std::string &str, std::size_t pos = 0);
		static void			replaceAll(std::string &to_change, const std::string &word, const std::string &replace, std::size_t pos = 0);
		
		static std::string	getFileName(const std::string &path);
		template <typename R, typename A>
		static R convert(const A &value);
};

template <typename R, typename A>
R Utils::convert(const A &value)
{
	std::stringstream ss;
	R res;

	ss << value;
	ss >> res;

	return res;
}

#endif