#include <iostream>
#include <random>

enum hands {rock, paper, scissors, lizard, spock};

int random_int(int x, int y)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(x, y);
    return uni(rng);
}

void display_menu()
{
    std::cout << "Welcome to Rock, Paper, Scissor, Lizard, Spock.\n";
    std::cout << "To play, enter \'r\' for rock, \'p\' for paper,\n";
    std::cout << "\'s\' for scissors, \'l\' for lizard, and \'k\' for spock.\n";
    std::cout << "To exit, input \'e\'.\n";
    std::cout << "Please input your move: ";
}

std::string hand_chosen(char hand)
{
    switch(hand)
    {
        case 'r' : return "rock";
        case 'p' : return "paper";
        case 's' : return "scissors";
        case 'l' : return "lizard";
        case 'k' : return "spock";
    }
}

char computer_move()
{
    switch(random_int(0, 4))
    {
        case 0 : return 'r';
        case 1 : return 'p';
        case 2 : return 's';
        case 3 : return 'l';
        case 4 : return 'k';
    }
}

int compute_result(char user_input, char computer_input)
{
    switch(user_input)
    {
        case 'r' :
            if (computer_input == 'r')
            {
                std::cout << "Tie Game." << std::endl;
                return 0;
            }
            if (computer_input == 'p')
            {
                std::cout << "Paper covers Rock. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 's')
            {
                std::cout << "Rock crushes Scissors. You Win!" << std::endl;
                return 2;
            }
            if (computer_input == 'l')
            {
                std::cout << "Rock crushes Lizard. You win!" << std::endl;
                return 2;
            }
            if (computer_input == 'k')
            {
                std::cout << "Spock vaporizes Rock. Computer Wins!" << std::endl;
                return 1;
            }
        case 'p' :
            if (computer_input == 'r')
            {
                std::cout << "Paper covers Rock. You Win!" << std::endl;
                return 2;
            }
            if (computer_input == 'p')
            {
                std::cout << "Tie Game." << std::endl;
                return 0;
            }
            if (computer_input == 's')
            {
                std::cout << "Scissors cut Paper. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 'l')
            {
                std::cout << "Lizard eats Paper. Computer wins!" << std::endl;
                return 1;
            }
            if (computer_input == 'k')
            {
                std::cout << "Paper disproves Spock. You Win!" << std::endl;
                return 2;
            }
        case 's' :
            if (computer_input == 'r')
            {
                std::cout << "Rock crushes Scissors. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 'p')
            {
                std::cout << "Scissors cuts Paper. You Win!" << std::endl;
                return 2;
            }
            if (computer_input == 's')
            {
                std::cout << "Tie Game." << std::endl;
                return 0;
            }
            if (computer_input == 'l')
            {
                std::cout << "Scissors decapitates Lizard. You win!" << std::endl;
                return 2;
            }
            if (computer_input == 'k')
            {
                std::cout << "Spock smashes Scissors. Computer Wins!" << std::endl;
                return 1;
            }
        case 'l' :
            if (computer_input == 'r')
            {
                std::cout << "Rock crushes Lizard. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 'p')
            {
                std::cout << "Lizard eats Paper. You Win!" << std::endl;
                return 2;
            }
            if (computer_input == 's')
            {
                std::cout << "Scissors decapitates Lizard. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 'l')
            {
                std::cout << "Tie Game." << std::endl;
                return 0;
            }
            if (computer_input == 'k')
            {
                std::cout << "Lizard poisons Spock. You Win!" << std::endl;
                return 2;
            }
        case 'k' :
            if (computer_input == 'r')
            {
                std::cout << "Spock vaporizes Rock. You Win!" << std::endl;
                return 2;
            }
            if (computer_input == 'p')
            {
                std::cout << "Paper disproves Spock. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 's')
            {
                std::cout << "Spock smashes Scissors. You Win!" << std::endl;
                return 2;
            }
            if (computer_input == 'l')
            {
                std::cout << "Lizard poisons Spock. Computer Wins!" << std::endl;
                return 1;
            }
            if (computer_input == 'k')
            {
                std::cout << "Tie Game." << std::endl;
                return 0;
            }

    }
}

double calculate_percent(double x, double y)
{
    return x / y * 100;
}

int main() {
    int wins[3] = {0, 0, 0};
    int total_games_played = 0;
    char user_input;
    display_menu();
    std::cin >> user_input;
    while (user_input != 'e')
    {
        while(user_input != 'r' && user_input != 'p' && user_input != 's' && user_input != 'l' && user_input != 'k')
        {
            std::cout << "Please enter a valid input: ";
            std::cin >> user_input;
        }

        if (user_input == 'e')
        {
            break;
        }

        char computer_input = computer_move();

        std::cout << "\nPlayer Picks: " << hand_chosen(user_input) << "." << std::endl;
        std::cout << "Computer Picks: " << hand_chosen(computer_input) << "." << std::endl;

        int computed_result = compute_result(user_input, computer_input);

        ++wins[computed_result];
        ++total_games_played;

        std::cout << "\nEnter your next move or \'e\' to exit: ";
        std::cin >> user_input;
    }

    std::cout << "Thank You for playing!\n";
    std::cout << "You played a total of " << total_games_played << " games.\n";
    std::cout << "You won " << wins[2] << " games, which is " << calculate_percent(wins[2], total_games_played) << "% of games.\n";
    std::cout << "Computer won " << wins[1] << " games, which is " << calculate_percent(wins[1], total_games_played) << "% of games.\n";
    std::cout << "You tied " << wins[0] << " games, which is " << calculate_percent(wins[0], total_games_played) << "% of games.\n";

}