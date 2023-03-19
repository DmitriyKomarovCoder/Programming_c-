#include "console_parser.hpp"
#include "error.hpp"

CommandLineArgs parseCommandLineArgs(int argc, char *argv[]) {
    CommandLineArgs args = {"", "", "", "", ""};

    int opt;

    struct option long_options[] = {
        {"title", required_argument, nullptr, 't'},
        {"ratings", required_argument, nullptr, 'r'},
        {"basics", required_argument, nullptr, 'b'},
        {"date", required_argument, nullptr, 'd'},
        {"number", optional_argument, nullptr, 'n'},
        {nullptr, 0, nullptr, 0}
    };

    while ((opt = getopt_long(argc, argv, ":t:r:b:d:n:", long_options, nullptr)) != -1) {
        switch (opt) {
            case 't':
                args.fileNameTitle = optarg;
                break;
            case 'r':
                args.fileNameRatings = optarg;
                break;
            case 'b':
                args.fileNameBasics = optarg;
                break;
            case 'd':
                args.date = optarg;
                if (!isStringDigit(args.date)) {
                    std::cerr << "ERROR: Argument date is not a number" << std::endl;
                    exit(EXIT_FAILURE);
                }
                break;
            case 'n':
                args.numberMoviesString = optarg;
                break;
            default:
                std::cerr << "Invalid option" << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    if (args.date.empty() || args.fileNameBasics.empty() ||
        args.fileNameRatings.empty() || args.fileNameTitle.empty()
    ) {
        std::cerr << "ERROR: One of the required arguments is empty" << std::endl;
        exit(EXIT_FAILURE);
    }
    return args;
}
