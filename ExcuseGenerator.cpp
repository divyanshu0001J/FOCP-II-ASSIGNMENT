#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>

// ANSI Escape Codes
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GOLD    "\033[38;5;220m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"

// Function to replace all {name} placeholders
std::string personalizeExcuse(std::string_view templateExcuse,
                              const std::string& name) {

    std::string excuse(templateExcuse);
    const std::string placeholder = "{name}";

    size_t position = 0;

    // Replace ALL occurrences safely
    while ((position = excuse.find(placeholder, position))
            != std::string::npos) {

        excuse.replace(position, placeholder.length(), name);
        position += name.length();
    }

    return excuse;
}

int main() {

    // Exactly 10 creative excuses
    const std::vector<std::string_view> excuses = {

        "{name}'s assignment was completed successfully, but the laptop restarted itself for a surprise Windows update speedrun.",

        "The AI tool helping {name} suddenly became self-aware and refused to finish homework for humans.",

        "{name} uploaded the assignment to the cloud, but apparently the cloud had weather issues today.",

        "Right before submission, {name}'s Wi-Fi disconnected so dramatically it deserved its own movie soundtrack.",

        "{name}'s browser opened 42 research tabs and sacrificed the assignment to save system memory.",

        "An autocorrect extension transformed {name}'s programming code into cooking instructions for garlic bread.",

        "{name} finished the homework at 2 AM, but the save button decided to take the night off.",

        "The assignment file entered corruption mode after {name}'s laptop battery hit 1% and started fighting for survival.",

        "{name}'s code worked perfectly until someone said, 'Can you demonstrate it live?'",

        "{name} spent hours debugging only to discover the real bug was emotional damage."
    };

    // Modern Random Engine
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<size_t>
        distribution(0, excuses.size() - 1);

    std::string studentName;
    char choice = 'y';

    int previousIndex = -1;

    // Banner
    std::cout << GOLD << BOLD;
    std::cout << "=========================================================\n";
    std::cout << "            TECH EXCUSE GENERATOR 5000 🤖💻\n";
    std::cout << "=========================================================\n";
    std::cout << RESET << std::endl;

    // Main Loop
    while (choice == 'y' || choice == 'Y') {

        // Name Input
        std::cout << CYAN
                  << "Enter Student Name: "
                  << RESET;

        std::getline(std::cin, studentName);

        // Empty Name Protection
        if (studentName.empty()) {
            studentName = "The Student";
        }

        size_t randomIndex;

        // Prevent repeated excuses
        do {
            randomIndex = distribution(generator);
        }
        while (static_cast<int>(randomIndex) == previousIndex);

        previousIndex = static_cast<int>(randomIndex);

        // Generate Final Excuse
        std::string finalExcuse =
            personalizeExcuse(excuses[randomIndex], studentName);

        // Stylish Output
        std::cout << "\n"
                  << MAGENTA
                  << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                  << RESET;

        std::cout << GREEN << BOLD
                  << "⚡ Generated Excuse ⚡\n\n"
                  << RESET;

        std::cout << GREEN
                  << finalExcuse
                  << RESET << "\n";

        std::cout << MAGENTA
                  << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
                  << RESET;

        // Continue Option
        std::cout << CYAN
                  << "\nGenerate another excuse? (y/n): "
                  << RESET;

        std::cin >> choice;

        // Safe Buffer Cleanup
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        // Force lowercase handling
        choice = static_cast<char>(std::tolower(choice));

        std::cout << std::endl;
    }

    // Exit Message
    std::cout << RED << BOLD
              << "👋 Exiting Tech Excuse Generator. Goodbye!\n"
              << RESET;

    return 0;
}
