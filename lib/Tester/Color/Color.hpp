#ifndef __COLOR_HPP__
# define __COLOR_HPP__

# define ESC						"\033["

// Reset
# define COLOR_RESET					ESC "0m"

// Text styles
# define COLOR_BOLD						ESC "1m"
# define COLOR_DIM						ESC "2m"
# define COLOR_ITALIC					ESC "3m"
# define COLOR_UNDERLINE				ESC "4m"
# define COLOR_BLINK					ESC "5m"
# define COLOR_REVERSE					ESC "7m"
# define COLOR_HIDDEN					ESC "8m"

// Text (foreground) basic colors
# define COLOR_BLACK					ESC "30m"
# define COLOR_RED						ESC "31m"
# define COLOR_GREEN					ESC "32m"
# define COLOR_YELLOW					ESC "33m"
# define COLOR_BLUE						ESC "34m"
# define COLOR_MAGENTA					ESC "35m"
# define COLOR_CYAN						ESC "36m"
# define COLOR_WHITE					ESC "37m"

// Bright text colors (high intensity)
# define COLOR_BRIGHT_BLACK				ESC "90m"
# define COLOR_BRIGHT_RED				ESC "91m"
# define COLOR_BRIGHT_GREEN				ESC "92m"
# define COLOR_BRIGHT_YELLOW			ESC "93m"
# define COLOR_BRIGHT_BLUE				ESC "94m"
# define COLOR_BRIGHT_MAGENTA			ESC "95m"
# define COLOR_BRIGHT_CYAN				ESC "96m"
# define COLOR_BRIGHT_WHITE				ESC "97m"

// Background colors
# define COLOR_BG_BLACK					ESC "40m"
# define COLOR_BG_RED					ESC "41m"
# define COLOR_BG_GREEN					ESC "42m"
# define COLOR_BG_YELLOW				ESC "43m"
# define COLOR_BG_BLUE					ESC "44m"
# define COLOR_BG_MAGENTA				ESC "45m"
# define COLOR_BG_CYAN					ESC "46m"
# define COLOR_BG_WHITE					ESC "47m"

// Bright background colors
# define COLOR_BG_BRIGHT_BLACK			ESC "100m"
# define COLOR_BG_BRIGHT_RED			ESC "101m"
# define COLOR_BG_BRIGHT_GREEN			ESC "102m"
# define COLOR_BG_BRIGHT_YELLOW			ESC "103m"
# define COLOR_BG_BRIGHT_BLUE			ESC "104m"
# define COLOR_BG_BRIGHT_MAGENTA		ESC "105m"
# define COLOR_BG_BRIGHT_CYAN			ESC "106m"
# define COLOR_BG_BRIGHT_WHITE			ESC "107m"

# define COLOR_STYLE_WRAP(color_code, style_code, value) ESC style_code ";" color_code "m" value COLOR_RESET

// Text colors classiques
# define BLACK(value)					COLOR_STYLE_WRAP("30", "0", value)
# define RED(value)						COLOR_STYLE_WRAP("31", "0", value)
# define GREEN(value)					COLOR_STYLE_WRAP("32", "0", value)
# define YELLOW(value)					COLOR_STYLE_WRAP("33", "0", value)
# define BLUE(value)					COLOR_STYLE_WRAP("34", "0", value)
# define MAGENTA(value)					COLOR_STYLE_WRAP("35", "0", value)
# define CYAN(value)					COLOR_STYLE_WRAP("36", "0", value)
# define WHITE(value)					COLOR_STYLE_WRAP("37", "0", value)

// Text colors intenses (bright)
# define BRIGHT_BLACK(value)			COLOR_STYLE_WRAP("90", "0", value)
# define BRIGHT_RED(value)				COLOR_STYLE_WRAP("91", "0", value)
# define BRIGHT_GREEN(value)			COLOR_STYLE_WRAP("92", "0", value)
# define BRIGHT_YELLOW(value)			COLOR_STYLE_WRAP("93", "0", value)
# define BRIGHT_BLUE(value)				COLOR_STYLE_WRAP("94", "0", value)
# define BRIGHT_MAGENTA(value)			COLOR_STYLE_WRAP("95", "0", value)
# define BRIGHT_CYAN(value)				COLOR_STYLE_WRAP("96", "0", value)
# define BRIGHT_WHITE(value)			COLOR_STYLE_WRAP("97", "0", value)

// Styles (sans couleur, valeur 39)
# define BOLD(value)					ESC "1m" value COLOR_RESET
# define DIM(value)						ESC "2m" value COLOR_RESET
# define ITALIC(value)					ESC "3m" value COLOR_RESET
# define UNDERLINE(value)				ESC "4m" value COLOR_RESET
# define BLINK(value)					ESC "5m" value COLOR_RESET
# define REVERSE(value)					ESC "7m" value COLOR_RESET
# define HIDDEN(value)					ESC "8m" value COLOR_RESET

// Combinaisons couleurs + styles spécifiques (exemples)
# define RED_BOLD(value)				ESC "1;31m" value COLOR_RESET
# define GREEN_UNDERLINE(value)			ESC "4;32m" value COLOR_RESET
# define BLUE_ITALIC(value)				ESC "3;34m" value COLOR_RESET
# define MAGENTA_BLINK(value)			ESC "5;35m" value COLOR_RESET

// Background colors classiques
# define BG_BLACK(value)				COLOR_STYLE_WRAP("40", "0", value)
# define BG_RED(value)					COLOR_STYLE_WRAP("41", "0", value)
# define BG_GREEN(value)				COLOR_STYLE_WRAP("42", "0", value)
# define BG_YELLOW(value)				COLOR_STYLE_WRAP("43", "0", value)
# define BG_BLUE(value)					COLOR_STYLE_WRAP("44", "0", value)
# define BG_MAGENTA(value)				COLOR_STYLE_WRAP("45", "0", value)
# define BG_CYAN(value)					COLOR_STYLE_WRAP("46", "0", value)
# define BG_WHITE(value)				COLOR_STYLE_WRAP("47", "0", value)

// Background bright
# define BG_BRIGHT_BLACK(value)			COLOR_STYLE_WRAP("100", "0", value)
# define BG_BRIGHT_RED(value)			COLOR_STYLE_WRAP("101", "0", value)
# define BG_BRIGHT_GREEN(value)			COLOR_STYLE_WRAP("102", "0", value)
# define BG_BRIGHT_YELLOW(value)		COLOR_STYLE_WRAP("103", "0", value)
# define BG_BRIGHT_BLUE(value)			COLOR_STYLE_WRAP("104", "0", value)
# define BG_BRIGHT_MAGENTA(value)		COLOR_STYLE_WRAP("105", "0", value)
# define BG_BRIGHT_CYAN(value)			COLOR_STYLE_WRAP("106", "0", value)
# define BG_BRIGHT_WHITE(value)			COLOR_STYLE_WRAP("107", "0", value)

#endif
