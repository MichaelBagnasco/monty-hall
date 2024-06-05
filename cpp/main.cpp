#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 3); // For choosing doors randomly
    uniform_int_distribution<> coinFlip(0, 1); // For the random switch decision


    int rounds = 10000,
            keepWins = 0,
            switchWins = 0,
            randomSwitchWins = 0;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < rounds; ++i) {
        // Step 1: Randomly choose a prize door
        int prizeDoor = distr(gen);

        // Step 2: Randomly choose a contestant's initial door
        int chosenDoor = distr(gen);
        int revealedDoor;

        // Step 3: Determine the door to reveal
        if (chosenDoor == prizeDoor) {
            // The keep player will never switch, regardless of door reveal, so keep always wins in this scenario
            keepWins++;
        } else {
            // The switch player always switches, regardless of the door reveal.
            // The both the initial chosenDoor and the revealed door are always losing doors, so switching is always a win in this scenario
            switchWins++;

        }

        bool switchDecision = coinFlip(gen);
        if (switchDecision) {
            // If the initial chosen door is not the winning door, switching wins
            if (chosenDoor != prizeDoor) {
                randomSwitchWins++;
            }
        } else {
            // If the initial chosen door is the winning door, keeping wins
            if (chosenDoor == prizeDoor) {
                randomSwitchWins++;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    auto duration_ns = chrono::duration_cast<chrono::nanoseconds>(duration);


    float keepWinRate = (float) keepWins / rounds;
    float switchWinRate = (float) switchWins / rounds;
    float randomWinRate = (float) randomSwitchWins / rounds;
    cout << "Results after " << rounds << " rounds:\n";
    cout << "keep wins: " << keepWins << "\n";
    cout << "keep win rate: " << keepWinRate << "\n";
    cout << "switch wins: " << switchWins << "\n";
    cout << "switch win rate: " << switchWinRate << "\n";
    cout << "Random (50%) switch wins: " << randomSwitchWins << "\n";
    cout << "Random (50%) switch win rate: " << randomWinRate << "\n\n";

    cout
            << "Notice that switch win rate is always the inverse of the keep win rate (switch_win_rate = 1 - keep_win_rate), which is roughly 66.6% of the time"
            << "\n";
    cout << "Also notice that switching on a 50/50 coin flip brings the odds of winning to 50%.\n\n";

    cout << "Time taken for the simulation: ";


    if (duration.count() >= 0.1) {
        cout << duration.count() << " seconds\n";
    } else if (duration_ns.count() >= 100000) {
        cout << (float) duration_ns.count() / 100000 << " milliseconds\n";
    } else if (duration_ns.count() >= 1000) {
        cout << (float) duration_ns.count() / 1000 << " microseconds\n";
    } else {
        cout << duration_ns.count() << " nanoseconds\n";
    }

    return 0;
}