#ifndef __HTTPSYSTEMTREE_HPP__
# define __HTTPSYSTEMTREE_HPP__

# include "../Utils/Data.hpp"
# include <cstddef>
# include <string>
# include <vector>
# include <dirent.h>
# include "Node.hpp"

# define PATHS	"paths"
# define NAMES	"names"

typedef struct dirent *		Dirent;

class SystemTree : public Node
{
	public:
		static json	tree;
		
		enum status
		{
			SUCCESS,
			FAILED
		};

		SystemTree (void);
		SystemTree (const SystemTree &);
		SystemTree (SystemTree &&) noexcept;
		virtual ~SystemTree (void);
		SystemTree &operator=(const SystemTree &);
		SystemTree &operator=(SystemTree &&) noexcept;

		std::ostream& print(std::ostream& os) const;

		bool	load(const std::string &path, json &data, std::size_t deep = 1);

	private:
		json			_infos;

		std::string		checkPath(const std::string &path);
		bool			loadDirectory(const std::string &path, json &data, std::size_t deep = 0);
		void			initJsonInfo(json &data);
};

std::ostream& operator << ( std::ostream& os, const SystemTree &httpsystemtree);

#endif