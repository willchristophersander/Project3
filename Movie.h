#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Movie {
private:
    string Poster_Link;
    string Series_Title;
    int Released_Year;
    string Certificate;
    string Runtime;
    string Genre;
    float IMDB_Rating;
    string Overview;
    int Meta_score;
    string Director;
    string Star1, Star2, Star3, Star4;
    int No_of_Votes;
    long long Gross;

public:
    // Default constructor
    Movie()
            : Poster_Link(""), Series_Title(""), Released_Year(0), Certificate(""),
              Runtime(""), Genre(""), IMDB_Rating(0.0f), Overview(""), Meta_score(0),
              Director(""), Star1(""), Star2(""), Star3(""), Star4(""),
              No_of_Votes(0), Gross(0LL) {}
    // Constructor
    Movie(const string& poster, const string& title, int year, const string& certificate,
          const string& runtime, const string& genre, float rating, const string& overview,
          int metaScore, const string& director, const string& star1, const string& star2,
          const string& star3, const string& star4, int votes, long long gross)
            : Poster_Link(poster), Series_Title(title), Released_Year(year), Certificate(certificate),
              Runtime(runtime), Genre(genre), IMDB_Rating(rating), Overview(overview),
              Meta_score(metaScore), Director(director), Star1(star1), Star2(star2), Star3(star3),
              Star4(star4), No_of_Votes(votes), Gross(gross) {}

    // Getters
    string getPosterLink() const { return Poster_Link; }
    string getSeriesTitle() const { return Series_Title; }
    int getReleasedYear() const { return Released_Year; }
    string getCertificate() const { return Certificate; }
    string getRuntime() const { return Runtime; }
    string getGenre() const { return Genre; }
    float getIMDBRating() const { return IMDB_Rating; }
    string getOverview() const { return Overview; }
    int getMetaScore() const { return Meta_score; }
    string getDirector() const { return Director; }
    string getStar1() const { return Star1; }
    string getStar2() const { return Star2; }
    string getStar3() const { return Star3; }
    string getStar4() const { return Star4; }
    int getNoOfVotes() const { return No_of_Votes; }
    long long getGross() const { return Gross; }

    // Overloaded operator<< to print Movie details
   friend std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    return os << movie.getSeriesTitle() << " (" << movie.getReleasedYear() << ")";}

    // Static method to parse CSV and load Movie data
    static vector<Movie> parseCSV(const string& filename) {
        vector<Movie> movies;
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open the file!" << endl;
            return movies;
        }

        string line;
        getline(file, line); // Skip the header
        while (getline(file, line)) {
            stringstream s(line);
            vector<string> row;
            string field;

            // Parse each field using quotes for robustness (comma handling within quotes)
            while (getline(s, field, ',')) {
                if (field.front() == '"') {
                    string nextPart;
                    if (field.back() != '"') {
                        getline(s, nextPart, '"');
                        field += "," + nextPart;
                        getline(s, nextPart, ',');  // skip the remaining comma
                    }
                    field = field.substr(1, field.size() - 2); // Remove surrounding quotes
                }
                row.push_back(field);
            }

            if (row.size() >= 15) {
                int year = safeStoi(row[2], 0);
                int metaScore = safeStoi(row[8], 0);
                int noOfVotes = safeStoi(row[14], 0);
                long long gross = safeStoll(row[15], 0);
                float imdbRating = safeStof(row[6], 0.0f);

                Movie movie(
                        row[0],                              // Poster_Link
                        row[1],                              // Series_Title
                        year,                                // Released_Year
                        row[3],                              // Certificate
                        row[4],                              // Runtime
                        row[5],                              // Genre
                        imdbRating,                          // IMDB_Rating
                        row[7],                              // Overview
                        metaScore,                           // Meta_score
                        row[9],                              // Director
                        row[10],                             // Star1
                        row[11],                             // Star2
                        row[12],                             // Star3
                        row[13],                             // Star4
                        noOfVotes,                           // No_of_Votes
                        gross                                // Gross
                );

                movies.push_back(movie);
            }
        }

        return movies;
    }

    // Utility function to safely convert strings to integers
    static int safeStoi(const string& str, int defaultValue = 0) {
        try {
            return stoi(str);
        } catch (const invalid_argument&) {
            return defaultValue;
        } catch (const out_of_range&) {
            return defaultValue;
        }
    }

    // Utility function to safely convert strings to floats
    static float safeStof(const string& str, float defaultValue = 0.0f) {
        try {
            return stof(str);
        } catch (const invalid_argument&) {
            return defaultValue;
        } catch (const out_of_range&) {
            return defaultValue;
        }
    }

    // Utility function to safely convert strings to long long
    static long long safeStoll(const string& str, long long defaultValue = 0) {
        try {
            return stoll(str);
        } catch (const invalid_argument&) {
            return defaultValue;
        } catch (const out_of_range&) {
            return defaultValue;
        }
    }
    // Overloaded comparison operators based on Series_Title
    bool operator<(const Movie& other) const {
        return Series_Title < other.Series_Title;
    }

    bool operator>(const Movie& other) const {
        return Series_Title > other.Series_Title;
    }

    bool operator<=(const Movie& other) const {
        return Series_Title <= other.Series_Title;
    }

    bool operator>=(const Movie& other) const {
        return Series_Title >= other.Series_Title;
    }

    bool operator==(const Movie& other) const {
        return Series_Title == other.Series_Title;
    }

    // Getter for Series_Title (for testing and other purposes)
    string getTitle() const {
        return Series_Title;
    }
};

#endif