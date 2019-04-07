#include "./../includes/Game.class.hpp"

int		main(void) {

struct	timeval time;
Game	game = Game();


gettimeofday(&time, NULL);
srand((time.tv_sec * 100000) + (time.tv_usec / 100000));
game.start();
system("clear");
system("stty sane");
std::cout << "\x1b[31m\n  _____          __  __ ______    ______      ________ _____  _ \n / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |\n| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |\n| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |\n| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|\n \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)\n\x1b[0m" << std::endl;
return (0);
}
