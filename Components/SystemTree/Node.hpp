#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <dirent.h>
# include <sys/stat.h>
# include "../Utils/Utils.hpp"

typedef struct stat	Stat;

enum class NodeType
{
	DIRECTORY,
	FILE,
	LINK,
	SCHAR,
	BLOC,
	FIFO,
	SOCKET,
	UNKNOW
};

enum class NodeFilterType
{
	ONLY_HIDDEN,
	WITHOUT_HIDDEN,
	ALL
};

class Node
{
	protected:
		struct permission
		{
			bool	read;
			bool	write;
			bool	execute;
		};
		struct permissions
		{
			permission	user;
			permission	group;
			permission	other;
		};

		Node(void);
		Node(NodeFilterType filter);
		Node(const std::string &path, NodeFilterType filter = NodeFilterType::WITHOUT_HIDDEN);
		Node(const Node &other);
		Node(Node &&other);
		virtual ~Node(void);
		Node				&operator=(const Node &);
		Node				&operator=(Node &&);

		const std::string	&getName(void) const;
		const std::string	&getPath(void) const;
		const NodeType		&getType(void) const;
		const permissions	&getPersmissions(void) const;
		const std::string	getStringSize(void) const;
		std::size_t			getSize(void) const;

		std::size_t			getPathSize(void) const;
		std::size_t			getNameSize(void) const;

		const bool			&isInited(void) const;

		bool				init(const std::string &path);

		static NodeType		checkType(Stat stat);
		static permissions	checkPermissions(Stat stat);
		static bool			checkFilter(const std::string &path, const NodeFilterType &filter);

	private:
		Stat				_stat;
		std::string			_name;
		std::string			_path;
		std::size_t			_size;
		NodeType			_type;
		NodeFilterType		_filter;
		permissions			_permissions;
		bool				_is_inited;

};

#endif