#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

void readCSV();
bool isFloat(string str);
bool isAlph(string str);
enum Color {RED, BLACK};
class Movie{
public:
    Movie();
    Movie(string _genres, float _popularity, int _revenue, int _runtime, string _title, string actor1, string actor2, string actor3, string actor4, string actor5, string director, string producer, string screenplay, string editor);
    void PrintMovie(Movie* root);
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
    //for tree
    Movie *left, *right, *parent;
    bool color;
public:
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
struct RBTree{
    Movie* root;
    void rotateLeft(Movie* node1, Movie* node2);
    void rotateRight(Movie* node1, Movie* node2);
    void fixColor(Movie* node1, Movie* node2);
    RBTree(){
        root=NULL;
    }
    void insert(Movie* newNode);
    Movie* BSTInsert(Movie* root, Movie* newNode);
    void searchMovieTitle(string title,Movie* root);
    void searchMovieActor(string actor,Movie* root);
    void searchGenre(string actor,Movie* root);
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

void Movie::PrintMovie(Movie* root)
{
    cout << "Genres: " << root->genres << endl;
    cout << "Popularity: " << root->popularity << endl;
    cout << "Revenue: " << root->revenue << endl;
    cout << "Runtime: " << root->runtime << endl;
    cout << "Title: " << root->title << endl;
    cout << "Actor 1: " << root->actor1_name << endl;
    cout << "Actor 2: " << root->actor2_name << endl;
    cout << "Actor 3: " << root->actor3_name << endl;
    cout << "Actor 4: " << root->actor4_name << endl;
    cout << "Actor 5: " << root->actor5_name << endl;
    cout << "Director: " << root->director_name << endl;
    cout << "Producer: " << root->producer_name << endl;
    cout << "Screenplay by: " << root->screenplay_writer_name << endl;
    cout << "Editor: " << root->editor_name << endl;
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
void RBTree::rotateLeft(Movie *root, Movie *newNode) {
    Movie* rightPT = newNode->right;
    newNode->right=rightPT->left;
    if(newNode->right!=NULL){
        newNode->right->parent=newNode;
    }
    rightPT->parent=newNode->parent;
    if(newNode->parent ==NULL){
        root=rightPT;
    }
    else if(newNode==newNode->parent->left){
        newNode->parent->left=rightPT;
    }
    else{
        newNode->parent->right=rightPT;
    }
    rightPT->left = newNode;
    newNode->parent=rightPT;
}
void RBTree::rotateRight(Movie *root, Movie *newNode) {
    Movie* leftPT = newNode->left;
    newNode->left = leftPT->right;
    if(newNode->left!=NULL){
        newNode->left->parent=newNode;
    }
    leftPT->parent=newNode->parent;
    if(newNode->parent==NULL){
        root=leftPT;
    }
    else if(newNode == newNode->parent->left){
        newNode->parent->left=leftPT;
    }
    else{
        newNode->parent->left = leftPT;
    }
    leftPT->right=newNode;
    newNode->parent=leftPT;
}
void RBTree::fixColor(Movie *root, Movie *newNode) {
    Movie* parentPointer = NULL;
    Movie* grandParentPointer = NULL;

    while((newNode!=root) && (newNode->color != BLACK) && (newNode->parent->color==RED)){
        parentPointer = newNode->parent;
        grandParentPointer = newNode->parent->parent;

        //if parent of pointer is left child of grandparent pointer
        if(parentPointer==grandParentPointer->left){
            Movie* unclePointer = grandParentPointer->right;
            //if the uncle pointer is also red only recoloring required
            if(unclePointer != NULL && unclePointer->color == RED){
                grandParentPointer->color=RED;
                parentPointer->color=BLACK;
                unclePointer->color=BLACK;
                newNode=grandParentPointer;
            }
                //if newNode is right child of its parent left rotation is required
            else{
                if(newNode==parentPointer->right){
                    rotateLeft(root,parentPointer);
                    newNode=parentPointer;
                    parentPointer=newNode->parent;
                }
                rotateRight(root,grandParentPointer);
                swap(parentPointer->color, grandParentPointer->color);
                newNode=parentPointer;
            }
        }
            //if parent of newNode is the right child of grandparent pointer
        else{
            Movie* unclePointer=grandParentPointer->left;
            //if the uncle of the newNode is also red only recoloring required
            if((unclePointer!=NULL) && (unclePointer->color==RED)){
                grandParentPointer->color=RED;
                parentPointer->color=BLACK;
                unclePointer->color=BLACK;
                newNode=grandParentPointer;
            }
            else{
                //newNode is left child of its parent right rotation required
                if(newNode==parentPointer->left){
                    rotateRight(root,parentPointer);
                    newNode=parentPointer;
                    parentPointer=newNode->parent;
                }
                rotateLeft(root,grandParentPointer);
                swap(parentPointer->color,grandParentPointer->color);
                newNode=parentPointer;
            }
        }
    }
    root->color=BLACK;
}
Movie* RBTree::BSTInsert(Movie *root, Movie *newNode) {
    if(root==NULL){ //if tree is empty return new node
        return newNode;
    }
    if(newNode->title[0] < root->title[0]){
        root->left = BSTInsert(root->left, newNode);
        root->left->parent=root;
    }
    else if(newNode->title[0] > root->title[0]){
        root->right = BSTInsert(root->right, newNode);
        root->right->parent=root;
    }
    return root;
}
void RBTree::insert(Movie* newNode) {
    root = BSTInsert(root, newNode);
    fixColor(root, newNode);
}
void RBTree::searchMovieTitle(string title, Movie* root) {
    bool printed=false;
    if(root==NULL){
        return;
    }
    searchMovieTitle(title,root->left);
    if(title==root->title){
        root->PrintMovie(root);
        printed=true;
    }
    searchMovieTitle(title,root->right);
    if(printed==false){
        cout <<"Movie Title Is Not Documented"<<endl;
    }
}
void RBTree::searchMovieActor(string actor, Movie *root) {
    vector<Movie*> vecToPrint;
    if(root==NULL){
        return;
    }
    searchMovieTitle(actor,root->left);
    if(actor==root->actor1_name || actor==root->actor2_name ||actor==root->actor3_name || actor==root->actor4_name || actor==root->actor5_name){
        vecToPrint.push_back(root);
    }
    searchMovieTitle(actor,root->right);

    if(!vecToPrint.empty()) {
        sort(vecToPrint.begin(), vecToPrint.end());
        for (int i = 0; i < vecToPrint.size(); i++) {
            root->PrintMovie(vecToPrint[i]);
        }
    }
    else{
        cout << "There are no documented movies with that actor."<<endl;
    }
}
void RBTree::searchGenre(string genre, Movie *root) {
    vector<Movie*> vecToPrint;
    if(root==NULL){
        return;
    }
    searchMovieTitle(genre,root->left);
    if(genre==root->genres){
        vecToPrint.push_back(root);
    }
    searchMovieTitle(genre,root->right);

    if(!vecToPrint.empty()) {
        sort(vecToPrint.begin(), vecToPrint.end());
        for (int i = 0; i < vecToPrint.size(); i++) {
            root->PrintMovie(vecToPrint[i]);
        }
    }
    else{
        cout << "There are no documented movies with that genre."<<endl;
    }
}
int main()
{
    readCSV();

    string input = "";
    while (input != "-1") {
        string movieTitle = "";
        string movieActor = "";
        string movieGenre = "";
        Movie userInput;

        //are empty
        Movie* root;
        RBTree tree;

        cout << "Search by Movie (1), actor (2), or genre(3). Exit with -1 \n";
        cin >> input;
        switch (stoi(input)) {
            case 1:
                cout << "Insert Movie Title: ";
                cin >> movieTitle;
                // search
                //searchMovieTitle()
                break;
            case 2:
                cout << "Insert an actor: ";
                cin >> movieActor;
                // search
                //searchActorName()
                break;
            case 3:
                cout << "Insert a genre: ";
                cin >> movieGenre;
                // search
                //searchGenre()
                break;
        }
    }
}
void readCSV()
{
    fstream inClean("AllMoviesDetailsCleaned.csv");
    fstream inRaw("AllMoviesCastingRaw.csv");
    int count = 0; // keeps track of how many movies added.
    int temp = 0; // keeps track of how many lines traversed.
    string line; // used to set detailsCleaned values
    string item; // used to set castingRaw values
    getline(inClean, line);
    getline(inRaw, line);
    int diff = 0;

    if (inClean.is_open() && inRaw.is_open()) {
        // can lower conditional when testing so the entire file doesn't need to be run every time. Takes appprox 2mins 10s without adding to data structure
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

            if(getline(inClean, line)) { // gets data from detailsCleaned.csv

                istringstream stream(line);
                // runs through each column, but only collects some
                getline(stream, _idC, ';');
                getline(stream, item, ';'); // item is used as a placeholder for values not collected
                getline(stream, _genres, ';');
                getline(stream, item, ';');
                getline(stream, item, ';');
                getline(stream, item, ';');
                getline(stream, item, ';');
                getline(stream, _popularity, ';');
                while (!isFloat(_popularity)) { // in some cases there is a ; not as a delimiter.
                    //This checks to see if the next value is a float as it should be instead of a string continued from the previous column
                    getline(stream, _popularity, ';');
                }
                if (_popularity == "")
                    _popularity = "0.0";
                getline(stream, item, ';');
                getline(stream, item, ';');
                getline(stream, item, ';');
                getline(stream, _revenue, ';');
                if (_revenue == "")
                    _revenue = "0"; // can cause problems otherwise when converting to an int
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

            }

            if(getline(inRaw, item)) { // gets data from castingRaw.csv
                istringstream stream2(item);

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

            }
            temp++;

            if (_idC != _idR) // should not occur. If IDs of the movies do not match then the data from both csv files will also not match
                cout << "Clean: " << _idC << "Raw: " << _idR << endl;
            Movie node;// = Movie(_genres, stof(_popularity), stoi(_revenue), stoi(_runtime), _title, _actor1_name, _actor2_name, _actor3_name, _actor4_name, _actor5_name, _director_name, _producer_name, _screenplay_writer_name, _editor_name);
            RBTree tree; //tree object
            if (isAlph(_title) && temp !=198152 ) { // bad data at 198152
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
                Movie* pointer = &node;
                tree.insert(pointer);
                count++;
            }
            //else
            //cout << "not letter " << _title << " " << _idC << endl;

        }
    }
}

bool isFloat(string str)
{
    for(int i = 0; i < str.length(); i++) { // the non-numerical values occur if popularity is very close to 0. ex: 7.5E-5
        if ((str[i] != '.') && (str[i] != 'E') && (str[i] != 'e') && (str[i] != ',') && (str[i] != '-') && (str[i] != '0' && str[i] != '1'
                                                                                                            && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')) {
            return false; //|to do| if 'E', 'e', ',', or '-' then set to 0.0 as well
        }

    }
    return true;
}

bool isAlph(string str) // isaplha() function gives error on different language scripts, so a personalized function is needed to remove them.
{
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != 'A' && str[i] !='a' && str[i] != 'B' && str[i] != 'b' && str[i] != 'C' && str[i] != 'c' && str[i] != 'D' && str[i] != 'd'
            && str[i] != 'E' && str[i] != 'e' && str[i] != 'F' && str[i] != 'f' && str[i] != 'G' && str[i] != 'g' && str[i] != 'H' && str[i] != 'h'
            && str[i] != 'I' && str[i] != 'i' && str[i] != 'J' && str[i] != 'j' && str[i] != 'K' && str[i] != 'k' && str[i] != 'L' && str[i] != 'l'
            && str[i] != 'M' && str[i] != 'm' && str[i] != 'N' && str[i] != 'n' && str[i] != 'O' && str[i] != 'o' && str[i] != 'P' && str[i] != 'p'
            && str[i] != 'Q' && str[i] != 'q' && str[i] != 'R' && str[i] != 'r' && str[i] != 'S' && str[i] != 's' && str[i] != 'T' && str[i] != 't'
            && str[i] != 'U' && str[i] != 'u' && str[i] != 'V' && str[i] != 'v' && str[i] != 'W' && str[i] != 'w' && str[i] != 'X' && str[i] != 'x'
            && str[i] != 'Y' && str[i] != 'y' && str[i] != 'Z' && str[i] != 'z' && str[i] != ' ' && str[i] != ':' && str[i] != ',' && str[i] != '.'
            && str[i] != '\'' && str[i] != '0'&& str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6'
            && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '!' && str[i] != '(' && str[i] != ')' && str[i] != '-' && str[i] != '&'
            && str[i] != '?' && str[i] != '/' && str[i] != '"'){
            return false;
        }

    }
    return true;
}