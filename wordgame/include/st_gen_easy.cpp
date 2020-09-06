#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "random.hpp"
using namespace std;
using Random = effolkronium::random_static;

int main()
{
//for a vector of strings *TEST CODE*
/*	vector <string> str;
	str.push_back("bee");
	str.push_back("ant");
	str.push_back("bug");
	for (int i = 0; i < str.size(); i++)
		cout<<str[i]<<endl; */	
	
//using Random from effolkronium library to create random numbers *TEST CODE*
	//cout<<Random::get(1, 100)<<endl;	
	
//to create a vectors of ints from 0->199 (200 total) *TEST CODE*
/*	vector <int> vec;
	for (int i = 0; i <200; i++)
	{	vec.push_back(i);
		cout<<vec[i]<<"\t";}	*/		
		
//to create a vector of random ints from 0->199 (200 total) *TEST CODE*
/*	vector <int> randvec;
	for (int i = 0; i <200; i++)
	{	randvec.push_back(Random::get(1,200));
		cout<<randvec[i]<<"\t";}	*/
		
//to save input to an external file *TEST CODE*
/*	ofstream easy_2;
	easy_2.open("easy_2.txt");
	easy_2<<"This is where the list of easy 2 letter words will be stored.\n";
	easy_2<<"this line was added to the easy_2 file\n";
	easy_2.close();*/		

//********************************************************************//		
//**USE TO BUILD WORD DATABASE FASTER**
//to create an txt file to store list of 2 letter strings
//I will rewrite these as a functions or classs later on, but just wanted
//	to get working code started
//********************************************************************//
/*	string w2;
	int i2=0;
	
	cout<<"Enter the 2 letter word to add to the vector ('quitapp' to exit): "<<endl;
	cin>>w2;
	
	ofstream easy_2;
	easy_2.open("easy_2.txt");
	
	while (w2 != "quitapp")
	{	easy_2<<w2<<"\n";
		cout<<"Enter the 2 letter word to add to the vector ('quitapp' to exit): "<<endl;
		cin>>w2;
		i2++;
		
		if (w2 == "quitapp")
			easy_2.close();}*/
//********************************************************************//
	
//to import the txt file of saved words into a vector
	vector<string>easy2;
	
	ifstream in("words_alpha.txt");
	string str;
	
	while(getline(in,str))
	{	if(str.size()>0)
		easy2.push_back(str);}
	

//print back the vector to check that it matches the external txt list
/*	cout<<"Easy words in order"<<endl;
	for (int i = 0; i < easy2.size(); i++)
		cout<<easy2[i]<<"\n";*/
	
//print back the vector in a random order from an external txt list
//change i<easy2.size to a different number to create a longer
//	randomized word list
	cout<<endl<<"Easy words randomized"<<endl;

	
	vector <int> easyrand;
	int a = easy2.size();
	for (int i = 0; i < 100000; i++)
	{	easyrand.push_back(Random::get(0,a-1));
		cout<< "[" << i << "] = " << easy2[easyrand[i]]<<endl;}

}

std::vector<std::string> st_gen_easy::getWords(){

}