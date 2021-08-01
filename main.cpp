#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

void readCSV();
bool isFloat(string str);

class Movie{
public:
	Movie();
	Movie(string _genres, float _popularity, int _revenue, int _runtime, string _title, string actor1, string actor2, string actor3, string actor4, string actor5, string director, string producer, string screenplay, string editor);
	void PrintMovie();
	void setGenres(string _genres);
	void setPop(string _pop);
	void setRevenue(string _revenue);
	void setRuntime(string _runtime);
	void setTitle(string _title);
	void setActor1(string _actor1);
	void setActor2(string _actor2);
	void setActor3(string _actor3);
	void setActor4(string _actor4);
	void setActor5(string _actor5);
	void setDirector(string _director);
	void setProducer(string _producer);
	void setScreenplay(string _screenplay);
	void setEditor(string _editor);
private:
	// from Clean in order listed
	//int idC;
	//int budget;
	string genres;
	//string imdb_id;
	//string original_language;
	//string original_title;
	//string overview;
	float popularity;
	//string production_company;
	//string production_country;
	//string release_date;
	string revenue;
	int runtime;
	//string spoken_languages;
	//string status;
	//string tagline;
	string title;
	//float vote_average;
	//int vote_count;
	//int production_companies_number;
	//int production_countries_number;
	//int spoken_languages_number;

	// from Raw in order listed
	//int idR;
	string actor1_name;
	//int actor1_gender; // 0 unknown, 1 female, 2 male
	string actor2_name;
	//int actor2_gender;
	string actor3_name;
	//int actor3_gender;
	string actor4_name;
	//int actor4_gender;
	string actor5_name;
	//int actor5_gender;
	//int actor_number;
	string director_name;
	//int director_gender;
	//int director_number;
	string producer_name;
	//int producer_number;
	string screenplay_writer_name;
	string editor_name;
};

Movie::Movie()
{
	genres = "";
	popularity = 0;
	revenue = "";
	runtime = 0;
	title = "";
	actor1_name = "";
	actor2_name = "";
	actor3_name = "";
	actor4_name = "";
	actor5_name = "";
	director_name = "";
	producer_name = "";
	screenplay_writer_name = "";
	editor_name = "";
}

Movie::Movie(string _genres, float _popularity, int _revenue, int _runtime, string _title, string actor1, string actor2, string actor3, string actor4, string actor5, string director, string producer, string screenplay, string editor)
{
	genres = _genres;
	popularity = _popularity;
	revenue = _revenue;
	runtime = _runtime;
	title = _title;
	actor1_name = actor1;
	actor2_name = actor2;
	actor3_name = actor3;
	actor4_name = actor4;
	actor5_name = actor5;
	director_name = director;
	producer_name = producer;
	screenplay_writer_name = screenplay;
	editor_name = editor;
}

void Movie::PrintMovie() 
{
	cout << "Genres: " << genres << endl;
	cout << "Popularity: " << popularity << endl;
	cout << "Revenue: " << revenue << endl;
	cout << "Runtime: " << runtime << endl;
	cout << "Title: " << title << endl;
	cout << "Actor 1: " << actor1_name << endl;
	cout << "Actor 2: " << actor2_name << endl;
	cout << "Actor 3: " << actor3_name << endl;
	cout << "Actor 4: " << actor4_name << endl;
	cout << "Actor 5: " << actor5_name << endl;
	cout << "Director: " << director_name << endl;
	cout << "Producer: " << producer_name << endl;
	cout << "Screenplay by: " << screenplay_writer_name << endl;
	cout << "Editor: " << editor_name << endl;
}
void Movie::setGenres(string _genres) {
	genres = _genres;
}
void Movie::setPop(string _pop) {
	popularity = stof(_pop);
}
void Movie::setRevenue(string _revenue) {
	revenue = _revenue;
}
void Movie::setRuntime(string _runtime) {
	runtime = stoi(_runtime);
}
void Movie::setTitle(string _title) {
	title = _title;
}
void Movie::setActor1(string _actor1) {
	actor1_name = _actor1;
}
void Movie::setActor2(string _actor2) {
	actor2_name = _actor2;
}
void Movie::setActor3(string _actor3) {
	actor3_name = _actor3;
}
void Movie::setActor4(string _actor4) {
	actor4_name = _actor4;
}
void Movie::setActor5(string _actor5) {
	actor5_name = _actor5;
}
void Movie::setDirector(string _director) {
	director_name = _director;
}
void Movie::setProducer(string _producer) {
	producer_name = _producer;
}
void Movie::setScreenplay(string _screenplay) {
	screenplay_writer_name = _screenplay;
}
void Movie::setEditor(string _editor) {
	editor_name = _editor;
}
int main()
{
	readCSV();
	std::cout << "test";
}
void readCSV()
{
	fstream inClean("AllMoviesDetailsCleaned.csv");
	fstream inRaw("AllMoviesCastingRaw.csv");
	
	int temp = 0;
	string line;
	string item;
	getline(inClean, line);
	getline(inRaw, line);
	int diff = 0;
	if (inClean.is_open() && inRaw.is_open()) {
	while (temp < 328842) { //328842 is max, error after 198152-> correlates to id: 314304
		string _idC = "";
		string _genres = "";
		string _popularity = ".1"; // float
		string _revenue = "1"; // int
		string _runtime = "1"; // int
		string _title = "";

		string _idR = "";
		string _actor1_name = "";
		string _actor2_name = "";
		string _actor3_name = "";
		string _actor4_name = "";
		string _actor5_name = "";
		string _director_name = "";
		string _producer_name = "";
		string _screenplay_writer_name = "";
		string _editor_name = "";
		
		//cout << line << endl << endl;
		if(getline(inClean, line)) { // while id is < raw id
			
			istringstream stream(line);
			//cout << line << endl;
			getline(stream, _idC, ';');
			getline(stream, item, ';');
			getline(stream, _genres, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, _popularity, ';');
			while (!isFloat(_popularity)) {
				getline(stream, _popularity, ';');
				//cout << _popularity << endl;
			}
			if (_popularity == "")
				_popularity = "0.0";
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, _revenue, ';');
			if (_revenue == "")
				_revenue = "0";
			getline(stream, _runtime, ';');
			if (_runtime == "")
				_runtime = "0";
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, _title, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			getline(stream, item, ';');
			//cout << _idC << endl;

		}
		
		//cout << item << endl << endl;
		if(getline(inRaw, item)) {
			istringstream stream2(item);
			//cout << item << endl;
			getline(stream2, _idR, ';');
			getline(stream2, _actor1_name, ';');
			getline(stream2, line, ';');
			getline(stream2, _actor2_name, ';');
			getline(stream2, line, ';');
			getline(stream2, _actor3_name, ';');
			getline(stream2, line, ';');
			getline(stream2, _actor4_name, ';');
			getline(stream2, line, ';');
			getline(stream2, _actor5_name, ';');
			getline(stream2, line, ';');
			getline(stream2, line, ';');
			getline(stream2, _director_name, ';');
			getline(stream2, line, ';');
			getline(stream2, line, ';');
			getline(stream2, _producer_name, ';');
			getline(stream2, line, ';');
			getline(stream2, _screenplay_writer_name, ';');
			getline(stream2, _editor_name, ';');
			//cout << _idR << endl << endl;
		}
		temp++;
		//cout << temp << endl;
		if (_idC != _idR)
			cout << "Clean: " << _idC << "Raw: " << _idR << endl;
		Movie node;// = Movie(_genres, stof(_popularity), stoi(_revenue), stoi(_runtime), _title, _actor1_name, _actor2_name, _actor3_name, _actor4_name, _actor5_name, _director_name, _producer_name, _screenplay_writer_name, _editor_name);
		cout << temp << endl;
		cout << "Genres: " << _genres << endl;
		cout << "Popularity: " << _popularity << endl;
		cout << "Revenue: " << _revenue << endl;
		cout << "Runtime: " << _runtime << endl;
		cout << "Title: " << _title << endl;
		cout << "Actor 1: " << _actor1_name << endl;
		cout << "Actor 2: " << _actor2_name << endl;
		cout << "Actor 3: " << _actor3_name << endl;
		cout << "Actor 4: " << _actor4_name << endl;
		cout << "Actor 5: " << _actor5_name << endl;
		cout << "Director: " << _director_name << endl;
		cout << "Producer: " << _producer_name << endl;
		cout << "Screenplay by: " << _screenplay_writer_name << endl;
		cout << "Editor: " << _editor_name << endl << endl;
		node.setGenres(_genres);
		node.setPop(_popularity);
		node.setRevenue(_revenue);
		node.setRuntime(_runtime);
		node.setTitle(_title);
		node.setActor1(_actor1_name);
		node.setActor2(_actor2_name);
		node.setActor3(_actor3_name);
		node.setActor4(_actor4_name);
		node.setActor5(_actor5_name);
		node.setDirector(_director_name);
		node.setProducer(_producer_name);
		node.setScreenplay(_screenplay_writer_name);
		node.setEditor(_editor_name);
		//node.PrintMovie();
		// Add to tree.
		
	}
	}
}

bool isFloat(string str)
{
	for(int i = 0; i < str.length(); i++) {
		if ((str[i] != '.') && (str[i] != 'E') && (str[i] != 'e') && (str[i] != ',') && (str[i] != '-') && (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')) {
			//cout << endl << "------------" << str << "--------------" << endl;
			return false; //|to do| if 'E', 'e', ',', or '-' then set to 0.0 as well
		}

	}
	return true;
	//cout << endl << "------------" << str << "--------------" << endl;
}