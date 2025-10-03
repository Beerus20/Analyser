#include "Log/Log.hpp"

// tester project
int	main(void)
{
	Log::addFilter(Log::ERROR);
	Log::info("test info");
	Log::debug("test debug");
	Log::warning("test warning");
	Log::error("test error");
	Log::sep();
	Log::addFilter(Log::WARNING);
	Log::info("test info");
	Log::debug("test debug");
	Log::warning("test warning");
	Log::error("test error");
	Log::sep();
	Log::addFilter(Log::INFO);
	Log::info("test info");
	Log::debug("test debug");
	Log::warning("test warning");
	Log::error("test error");
	Log::sep();
	Log::addFilter(Log::DEBUG);
	Log::info("test info");
	Log::debug("test debug");
	Log::warning("test warning");
	Log::error("test error");
	Log::sep();
	return (0);
}