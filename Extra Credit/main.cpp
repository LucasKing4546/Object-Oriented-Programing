#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

const int ALPHABET_SIZE = 26;
const int TOP_N = 3;

void read_distribution(const string &filename, double distribution[ALPHABET_SIZE]) {
    ifstream fin(filename);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fin >> distribution[i];
    }
    fin.close();
}

void compute_histogram(const string &text, double histogram[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        histogram[i] = 0.0;
    }
    int total = 0;
    for (char c : text) {
        if (isalpha(c)) {
            histogram[c - 'a']++;
            total++;
        }
    }
    if (total > 0) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            histogram[i] /= total;
        }
    }
}

double chi_squared_distance(const double hist1[ALPHABET_SIZE], const double hist2[ALPHABET_SIZE]) {
    double chi = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (hist2[i] > 0) {  // Avoid division by zero
            double diff = hist1[i] - hist2[i];
            chi += (diff * diff) / hist2[i];
        }
    }
    return chi;
}

double euclidean_distance(const double hist1[ALPHABET_SIZE], const double hist2[ALPHABET_SIZE]) {
    double sum = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        double diff = hist1[i] - hist2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double cosine_distance(const double hist1[ALPHABET_SIZE], const double hist2[ALPHABET_SIZE]) {
    double dot = 0.0, norm1 = 0.0, norm2 = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        dot += hist1[i] * hist2[i];
        norm1 += hist1[i] * hist1[i];
        norm2 += hist2[i] * hist2[i];
    }
    if (norm1 == 0 || norm2 == 0)
        return 1.0;  // Maximum distance if one vector is zero.
    double cosine_similarity = dot / (sqrt(norm1) * sqrt(norm2));
    return 1.0 - cosine_similarity;
}

// Function to encrypt text using the Caesar cipher with a given shift.
string caesar_encrypt(const string &text, int shift) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char((c - base + shift) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Function to decrypt text using the Caesar cipher with a given shift.
// Decryption can be performed by encrypting with (26 - shift).
string caesar_decrypt(const string &text, int shift) {
    return caesar_encrypt(text, 26 - (shift % 26));
}

// Function that tries all possible shifts to break the Caesar cipher using frequency analysis.
// It uses the provided distance_function (Chi-squared, Euclidean, or Cosine) to compare histograms.
void break_caesar_cipher(const string &text, int top_shifts[TOP_N], double top_distances[TOP_N],
                           double (*distance_function)(const double[], const double[])) {
    // Read standard English frequency distribution from file "distribution.txt".
    double english_distribution[ALPHABET_SIZE];
    ifstream fin("distribution.txt");
    if (!fin) {
        cerr << "Error opening distribution.txt. Using default distribution.\n";
        // Default approximate frequencies for English letters.
        double default_dist[ALPHABET_SIZE] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
                                              0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
                                              0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
                                              0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
                                              0.02758, 0.00978, 0.02360, 0.00150, 0.01974,
                                              0.00074};
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            english_distribution[i] = default_dist[i];
        }
    } else {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            fin >> english_distribution[i];
        }
        fin.close();
    }

    // Initialize top shifts/distances with high values.
    for (int i = 0; i < TOP_N; i++) {
        top_shifts[i] = -1;
        top_distances[i] = 1e9;  // Arbitrarily high value.
    }

    // Try all possible shifts (0 to 25).
    for (int shift = 0; shift < 26; shift++) {
        string decrypted = caesar_decrypt(text, shift);
        double hist[ALPHABET_SIZE];
        compute_histogram(decrypted, hist);
        double distance = distance_function(hist, english_distribution);

        // Insert into top results if this distance is among the lowest.
        for (int i = 0; i < TOP_N; i++) {
            if (distance < top_distances[i]) {
                for (int j = TOP_N - 1; j > i; j--) {
                    top_distances[j] = top_distances[j - 1];
                    top_shifts[j] = top_shifts[j - 1];
                }
                top_distances[i] = distance;
                top_shifts[i] = shift;
                break;
            }
        }
    }
}

// Helper function to display the histogram.
void display_histogram(const double histogram[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        cout << char('a' + i) << ": " << histogram[i] << "\n";
    }
}

int main() {
    string text = "";
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Read text from keyboard\n";
        cout << "2. Read text from file\n";
        cout << "3. Display current text\n";
        cout << "4. Encrypt text with Caesar cipher\n";
        cout << "5. Decrypt text with Caesar cipher\n";
        cout << "6. Compute frequency distribution of current text\n";
        cout << "7. Break Caesar cipher using frequency analysis\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline from the input buffer

        switch (choice) {
            case 1: {
                cout << "Enter text: ";
                getline(cin, text);
                break;
            }
            case 2: {
                cout << "Enter filename: ";
                string filename;
                getline(cin, filename);
                ifstream fin(filename);
                if (!fin) {
                    cout << "Error opening file.\n";
                } else {
                    stringstream ss;
                    ss << fin.rdbuf();
                    text = ss.str();
                    fin.close();
                    cout << "Text loaded successfully.\n";
                }
                break;
            }
            case 3: {
                cout << "\nCurrent text:\n" << text << "\n";
                break;
            }
            case 4: {
                int shift;
                cout << "Enter shift value: ";
                cin >> shift;
                cin.ignore();
                string encrypted = caesar_encrypt(text, shift);
                cout << "\nEncrypted text:\n" << encrypted << "\n";
                break;
            }
            case 5: {
                int shift;
                cout << "Enter shift value: ";
                cin >> shift;
                cin.ignore();
                string decrypted = caesar_decrypt(text, shift);
                cout << "\nDecrypted text:\n" << decrypted << "\n";
                break;
            }
            case 6: {
                double histogram[ALPHABET_SIZE];
                compute_histogram(text, histogram);
                cout << "\nFrequency distribution:\n";
                display_histogram(histogram);
                break;
            }
            case 7: {
                int top_shifts[TOP_N];
                double top_distances[TOP_N];
                cout << "Select distance metric:\n";
                cout << "1. Chi-Squared Distance\n";
                cout << "2. Euclidean Distance\n";
                cout << "3. Cosine Distance\n";
                int metric;
                cin >> metric;
                cin.ignore();
                double (*distance_function)(const double[], const double[]);
                switch(metric) {
                    case 1:
                        distance_function = chi_squared_distance;
                        break;
                    case 2:
                        distance_function = euclidean_distance;
                        break;
                    case 3:
                        distance_function = cosine_distance;
                        break;
                    default:
                        cout << "Invalid choice. Using Chi-Squared Distance by default.\n";
                        distance_function = chi_squared_distance;
                }
                break_caesar_cipher(text, top_shifts, top_distances, distance_function);
                cout << "\nTop " << TOP_N << " possible shifts:\n";
                for (int i = 0; i < TOP_N; i++) {
                    cout << "Shift: " << top_shifts[i] << " with distance: " << top_distances[i] << "\n";
                }
                break;
            }
            case 8: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 8);

    return 0;
}
