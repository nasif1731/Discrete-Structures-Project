//#include <iostream>
//#include <string>
//#include <vector>
//#include <iomanip>
//#include <conio.h>
//#include <fstream>
//
//using namespace std;
//ofstream Fout;
//
//vector<vector<bool>> makeTruthTable(vector<string> subStrings, vector<vector<bool>> propositionsValues, vector<char> propositions);
//void show(vector<char> propositions, vector<string> subStrings, vector<vector<bool>> propositionsValues, vector<vector<bool>> truthTable, vector<string> Premises);
//void getSubstrings(string, vector<string>&);
//void getPropositions(string str, vector<char>& propositions);
//int findProposition(vector<char>, char x);
//int findSubstring(string S1, string S2);
//vector<vector<bool>> getPremisesValues(vector<char> propositions, vector<vector<bool>> propositionsValues, vector<string> subStrings, vector<vector<bool>> truthTable, vector<string> Premises);
//bool CheckValidity(vector<vector<bool>> getPremisesValues);
//string CorrectBracket(string temp);
//bool AND(bool A, bool B);
//bool OR(bool A, bool B);
//bool IMPLIES(bool A, bool B);
//bool BICONDITIONAL(bool A, bool B);
//bool NEGATION(bool A);
//bool equivalenceChecker(vector<vector<bool>> LTT, vector<vector<bool>> RTT);
//
////([(p ^ q) -> r] <-> (p -> (q -> r)))
////([(p ->  q) ^ (q -> r)] -> (p -> r))
//
////(~(a^b)V~(~c^d))
//
//void P1()
//{
//	vector<string> sides[2]; // Vector to store sides
//	cout << "~ For Negation, ^ For And, V For Or, -> For Implies, <-> Biconditional\n\n";
//	for (int i = 0; i < 2; i++) // Loop To get sides
//	{
//		string temp;
//		while (true)
//		{
//			cout << "Enter Side " << i + 1 << ": ";
//			getline(cin, temp);
//			if (temp.size() >= 1)
//			{
//				break;
//			}
//		}
//		sides[i].push_back(temp);
//	}
//	vector<string> subStrings[2]; // Vector To Store Substrings
//	vector<char> propositions[2]; // Vector To Store Propositions
//	vector<vector<bool>> truthValues[2];
//	vector<vector<bool>> truthTable[2];
//
//	for (int n = 0; n < 2; n++)
//	{
//		// Get Propositions And Substrings Of sides
//		sides[n][0] = CorrectBracket(sides[n][0]);
//		getPropositions(sides[n][0], propositions[n]); // Funtion to get Propositions
//		getSubstrings(sides[n][0], subStrings[n]); // Function to get subStrings
//	
//		for (int i = 0; i < propositions[n].size(); i++) // Loop To Sort propositions In alphabetical order
//		{
//			for (int j = i + 1; j < propositions[n].size(); j++)
//			{
//				if (propositions[n][i] > propositions[n][j])
//				{
//					char x = propositions[n][j];
//					propositions[n][j] = propositions[n][i];
//					propositions[n][i] = x;
//				}
//			}
//		}
//		int propositionsize = propositions[n].size(); // Size Number Of Propositions
//		
//		truthValues[n].resize(propositionsize); // Vector To Store All Possible Values Of Proposition
//	
//		for (int i = 0; i < propositionsize; i++) // Loop To Store All Possible Values Of Proposition 
//		{
//			int temp = pow(2, propositionsize);
//			bool t = false;
//			int x = int(pow(2, propositionsize - i - 1));
//			for (int j = 0; j < temp; j++)
//			{
//				truthValues[n][i].push_back(t);
//				if ((j + 1) % x == 0)
//				{
//					t = !t;
//				}
//			}
//		}
//
//		truthTable[n] = makeTruthTable(subStrings[n], truthValues[n], propositions[n]); // Vector To Store The Truth Table Of All Substrings
//		cout << "Side " << n + 1 << " ";
//		show(propositions[n], subStrings[n], truthValues[n], truthTable[n], sides[n]); // Show Truth Table
//	}
//	if (equivalenceChecker(truthTable[0], truthTable[1]))
//	{
//		cout << "Equivalence\n";
//	}
//	else
//	{
//		cout << "Not Equivalence\n";
//	}
//}
//
//void P2()
//{
//	vector<string> Premises; // Vector to store premises and conclusion
//	cout << "~ For Negation, ^ For And, V For Or, -> For Implies, <-> Biconditional\n\n";
//	for (int i = 0; true; i++) // Loop To get Premises and conclusion
//	{
//		string temp;
//		while (true)
//		{
//			cout << "Enter Premise (0 To End) " << i + 1 << ": ";
//			getline(cin, temp);
//			if (temp.size() >= 1)
//			{
//				break;
//			}
//		}
//		Premises.push_back(temp);
//		if (Premises[i] == "0")
//		{
//			cout << "Enter Conclusion: ";
//			getline(cin, Premises[i]);
//			break;
//		}
//	}
//
//	vector<string> subStrings; // Vector To Store Substrings
//	vector<char> propositions; // Vector To Store Propositions
//	for (int i = 0; i < Premises.size(); i++) // Loop To Get Propositions And Substrings Of All Premises and Conclusion
//	{
//		Premises[i] = CorrectBracket(Premises[i]);
//		getPropositions(Premises[i], propositions); // Funtion to get Propositions
//		getSubstrings(Premises[i], subStrings); // Function to get subStrings
//	}
//
//	for (int i = 0; i < propositions.size(); i++) // Loop To Sort propositions In alphabetical order
//	{
//		for (int j = i + 1; j < propositions.size(); j++)
//		{
//			if (propositions[i] > propositions[j])
//			{
//				char x = propositions[j];
//				propositions[j] = propositions[i];
//				propositions[i] = x;
//			}
//		}
//	}
//
//	int propositionsize = propositions.size(); // Size Number Of Propositions
//	vector<vector<bool>> truthValues(propositionsize); // Vector To Store All Possible Values Of Proposition
//
//	for (int i = 0; i < propositionsize; i++) // Loop To Store All Possible Values Of Proposition 
//	{
//		int temp = pow(2, propositionsize);
//		bool t = false;
//		int x = int(pow(2, propositionsize - i - 1));
//		for (int j = 0; j < temp; j++)
//		{
//			truthValues[i].push_back(t);
//			if ((j + 1) % x == 0)
//			{
//				t = !t;
//			}
//		}
//	}
//
//	vector<vector<bool>> truthTable = makeTruthTable(subStrings, truthValues, propositions); // Vector To Store The Truth Table Of All Substrings
//	show(propositions, subStrings, truthValues, truthTable, Premises); // Show Truth Table
//}
//
//int main()
//{
//	Fout.open("Output.txt", ios::out);
//	while (true)
//	{
//		char ch;
//		cout << "Enter 1 For Equivalence, 2 For Argument Checker: ";
//		ch = _getche();
//		cout << endl;
//		switch (ch)
//		{
//		case '1':
//		{
//			P1();
//		}
//			break;
//
//		case '2':
//		{
//			P2();
//		}
//			break;
//		default:
//			break;
//		}
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//
//bool CheckValidity(vector<vector<bool>> PremisesValues) // Function To Check Validity Of Argument
//{
//	vector<int> VLines, IVLines; // VLines to store valid event Line Numbers, IVLines To Store Invalid Event Line Numbers
//	bool chk = false, chk2 = false; // chk To check if argument is valid, chk2 to check if argument is invalid
//	for (int i = 0; i < PremisesValues[0].size(); i++) // loop for each line of truth table
//	{
//		int count = 0; // count number of premises havung true value
//		for (int j = 0; j < PremisesValues.size() - 1; j++)
//		{
//			if (PremisesValues[j][i] == true)
//			{
//				count++;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (count == PremisesValues.size() - 1)// if count value is equal to the size of premises check if conclusion is true or not
//		{
//			if (PremisesValues[PremisesValues.size() - 1][i] == false)// if conclusion is false argument is invalid and push the index of that line to IVLines
//			{
//				IVLines.push_back(i + 1);
//				chk2 = true;
//			}
//			else // Push the values of valid event to VLines
//			{
//				VLines.push_back(i + 1);
//				chk = true;
//			}
//		}
//	}
//	if (chk2) // show Invalid Events
//	{
//		cout << "Argument Invalid At Line ";
//		Fout << "Argument Invalid At Line ";
//		for (int i = 0; i < IVLines.size(); i++)
//		{
//			cout << IVLines[i] << ", ";
//			Fout << IVLines[i] << ", ";
//		}
//		cout << "\b\b!\n";
//		Fout.seekp(-2, ios::cur);
//		Fout << "!\n";
//		return !chk2;
//	}
//	if (chk) // show Valid Events
//	{
//		cout << "Argument Valid At Line ";
//		Fout << "Argument Valid At Line ";
//		for (int i = 0; i < VLines.size(); i++)
//		{
//			cout << VLines[i] << ", ";
//			Fout << VLines[i] << ", ";
//		}
//		cout << "\b\b!\n";
//		Fout.seekp(-2, ios::cur);
//		Fout << "!\n";
//	}
//	return chk; // Return True If Valid Else False
//}
//
//vector<vector<bool>> getPremisesValues(vector<char> propositions, vector<vector<bool>> propositionsValues, vector<string> subStrings, vector<vector<bool>> truthTable, vector<string> Premises)
//{
//	// Fuction To generate Truth Table Of Premises
//	vector<vector<bool>> PremisesValues(Premises.size()); // Vector With Column Size Of Premises
//	for (int i = 0, j = 0; j < Premises.size(); i++)
//	{
//		if (i < subStrings.size() && subStrings[i] == Premises[j]) // if substring is equal to premise then add its truth table values into Premises truth table
//		{
//			for (int k = 0; k < truthTable.size(); k++)
//			{
//				PremisesValues[j].push_back(truthTable[k][i]);
//			}
//			j++;
//		}
//		else if (Premises[j].size() == 1) // if size == 1 means it is a single proposition then find its index in proposition vector and add its truth table values into premises truth table
//		{
//			int ind = findProposition(propositions, Premises[j][0]);
//			if (ind != -1)
//			{
//				for (int k = 0; k < propositionsValues[0].size(); k++)
//				{
//					PremisesValues[j].push_back(propositionsValues[ind][k]);
//				}
//			}
//			j++;
//			i--;
//		}
//	}
//	return PremisesValues;
//}
//
//void show(vector<char> propositions, vector<string> subStrings, vector<vector<bool>> propositionsValues, vector<vector<bool>> truthTable, vector<string> Premises)
//{
//	// Function To Show The Truth Tables
//	cout << "Complete Truth Table" << "\n\n";
//	for (int i = 0; i < propositions.size(); i++)
//	{
//		cout << "|  " << propositions[i] << "  ";
//		Fout << "|  " << propositions[i] << "  ";
//	}
//	for (int i = 0; i < subStrings.size(); i++)
//	{
//		cout << "|  " << subStrings[i] << "  ";
//		Fout << "|  " << subStrings[i] << "  ";
//	}
//	cout << "|" << endl;
//	Fout << "|" << endl;
//	for (int i = 0; i < propositionsValues[0].size(); i++)
//	{
//		char x;
//		for (int j = 0; j < propositionsValues.size(); j++)
//		{
//			if (propositionsValues[j][i] == 0)
//			{
//				x = 'F';
//			}
//			else
//			{
//				x = 'T';
//			}
//			cout << "|  " << x << "  ";
//			Fout << "|  " << x << "  ";
//		}
//		for (int j = 0; j < truthTable[0].size(); j++)
//		{
//			if (truthTable[i][j] == 0)
//			{
//				x = 'F';
//			}
//			else
//			{
//				x = 'T';
//			}
//			int sz = subStrings[j].size();
//			if (sz % 2 != 0)
//			{
//				sz = sz / 2 + 1;
//				cout << "|  " << setw(sz) << x << setw(sz + 1) << " ";
//				Fout << "|  " << setw(sz) << x << setw(sz + 1) << " ";
//			}
//			else
//			{
//				sz = sz / 2;
//				cout << "|  " << setw(sz) << x << setw(sz + 2) << " ";
//				Fout << "|  " << setw(sz) << x << setw(sz + 2) << " ";
//			}
//		}
//		cout << "|" << endl;
//		Fout << "|" << endl;
//	}
//
//
//	if (Premises.size() > 1)
//	{
//		cout << "Premises Truth Table\n\n";
//		cout << "\n\n\n";
//		Fout << "\n\n\n";
//
//		cout << " L# ";
//		Fout << " L# ";
//		for (int i = 0; i < propositions.size(); i++)
//		{
//			cout << "|  " << propositions[i] << "  ";
//			Fout << "|  " << propositions[i] << "  ";
//		}
//		for (int i = 0; i < Premises.size(); i++)
//		{
//			cout << "|  " << Premises[i] << "  ";
//			Fout << "|  " << Premises[i] << "  ";
//		}
//		cout << "|" << endl;
//		Fout << "|" << endl;
//
//		vector<vector<bool>> PremisesValues = getPremisesValues(propositions, propositionsValues, subStrings, truthTable, Premises);
//
//		for (int i = 0; i < propositionsValues[0].size(); i++)
//		{
//			char x;
//			cout << " " << setw(2) << i + 1 << " ";
//			Fout << " " << setw(2) << i + 1 << " ";
//			for (int j = 0; j < propositionsValues.size(); j++)
//			{
//				if (propositionsValues[j][i] == 0)
//				{
//					x = 'F';
//				}
//				else
//				{
//					x = 'T';
//				}
//				cout << "|  " << x << "  ";
//				Fout << "|  " << x << "  ";
//			}
//			for (int j = 0; j < PremisesValues.size(); j++)
//			{
//				if (PremisesValues[j][i] == 0)
//				{
//					x = 'F';
//				}
//				else
//				{
//					x = 'T';
//				}
//				int sz = Premises[j].size();
//				if (sz % 2 != 0)
//				{
//					sz = sz / 2 + 1;
//					cout << "|  " << setw(sz) << x << setw(sz + 1) << " ";
//					Fout << "|  " << setw(sz) << x << setw(sz + 1) << " ";
//				}
//				else
//				{
//					sz = sz / 2;
//					cout << "|  " << setw(sz) << x << setw(sz + 2) << " ";
//					Fout << "|  " << setw(sz) << x << setw(sz + 2) << " ";
//				}
//			}
//			cout << "|" << endl;
//			Fout << "|" << endl;
//		}
//
//		cout << "\n\n\n";
//		Fout << "\n\n\n";
//		if (CheckValidity(PremisesValues))
//		{
//			cout << "Argument Valid!";
//			Fout << "Argument Valid!";
//		}
//		else
//		{
//			cout << "Invalid Argument!";
//			Fout << "Invalid Argument!";
//		}
//	}
//	Fout.close();
//	cout << "\n\n";
//}
//
//void getSubstrings(string S, vector<string>& subStrings)
//{
//	// Function To Get Sub Parts Of Premises and Conclusion
//	vector<int> ind;
//	int sz = S.size();
//	bool chk = false;
//	for (int i = 0; i < sz; i++)
//	{
//		if (S[i] == '~') // If Negation Sign
//		{
//			if (S[i + 1] == '(' || S[i + 1] == '{' || S[i + 1] == '[') // Followed By Bracket Then chk = true
//			{
//				chk = true;
//			}
//			else // if it is a simple variable then push ~ + variable into substring
//			{
//				string t;
//				t.push_back('~');
//				t.push_back(S[i + 1]);
//				subStrings.push_back(t);
//			}
//		}
//		if (S[i] == '(' || S[i] == '{' || S[i] == '[')
//		{
//			ind.push_back(i); // push index value of starting brace index
//		}
//		else if (S[i] == ')' || S[i] == '}' || S[i] == ']') // else if closing brace
//		{
//			string temp;
//			for (int j = ind[ind.size() - 1]; j <= i; j++) // get the last starting brace index and copy it till current index
//			{
//				temp.push_back(S[j]);
//			}
//			bool chk2 = true;
//			for (int i = 0; i < subStrings.size(); i++)
//			{
//				if (temp == subStrings[i]) // if substring isnt alreaady in vector then push else continue
//				{
//					chk2 = false;
//					break;
//				}
//			}
//			if (chk2)
//			{
//				subStrings.push_back(temp); // push subtring to vector subStrings
//			}
//			if (chk) // chk true means brace was preceding by ~ sign
//			{
//				chk = false;
//				string t;
//				t.push_back('~');
//				t.append(temp);
//				subStrings.push_back(t); // push Negation Of previous Substring
//			}
//			ind.pop_back(); // after pushing delete the last index value of starting brace
//		}
//	}
//}
//
//void getPropositions(string str, vector<char>& propositions)
//{
//	// Function To get variables/Propositions from the string
//	int lengthStr = str.length();
//	for (int i = 0; i < lengthStr; i++)
//	{
//		if (islower(str[i])) // if lowercase alphabet proceed to check if it already exist in vector or not
//		{
//			bool chk = true; // chk for if the variable already exist in vector
//			for (int j = 0; j < propositions.size(); j++)
//			{
//				if (str[i] == propositions[j]) // if condition is true means already exist in vector
//				{
//					chk = false;
//					break;
//				}
//			}
//			if (chk) // if chk true means the Proposition is unique
//			{
//				propositions.push_back(str[i]); // push proposition in vector
//			}
//		}
//	}
//}
//
//vector<vector<bool>> makeTruthTable(vector<string> subStrings, vector<vector<bool>> propositionsValues, vector<char> propositions)
//{
//	// Funtion To Make Truth table for every substring 
//	vector<vector<bool>> truthTable(propositionsValues[0].size()); // size of 2 raised to power number of propositions
//	for (int i = 0; i < propositionsValues[0].size(); i++)
//	{
//		for (int j = 0; j < subStrings.size(); j++)
//		{
//			if (subStrings[j].size() == 1)
//			{
//				continue;
//			}
//			string tempStr = subStrings[j];
//			for (int k = truthTable[i].size() - 1; k >= 0; k--)
//			{
//				int ind = findSubstring(tempStr, subStrings[k]); // find previos substrings in current temp string and store its index
//				if (ind != -1)
//				{
//					tempStr.replace(ind, subStrings[k].size(), to_string(truthTable[i][k])); // if ind != -1 then replace substring with truth value of that substring
//				}
//			}
//			char val[2] = { '9','9' }, op = '0', neg[2] = { '0','0' };
//			for (int k = 0, l = 0; k < tempStr.size(); k++)
//			{
//				if (islower(tempStr[k]) || tempStr[k] == '0' || tempStr[k] == '1') // initialize val with alphabet or truth value
//				{
//					val[l] = tempStr[k];
//					l++;
//				}
//				else if (tempStr[k] == '^' || tempStr[k] == 'V' || tempStr[k] == '-' || tempStr[k] == '<') // operator find 
//				{
//					op = tempStr[k];
//				}
//				else if (tempStr[k] == '~') // negation then neg[l] = 1 means true
//				{
//					neg[l] = '1';
//				}
//			}
//			int sz = 2;
//			if (val[1] == '9') //if second value is 9 means the operator is Negation only one value will be used
//			{
//				op = '~';
//				sz = 1;
//			}
//			bool temp[2] = { 0,0 }; // temp to store truth value of the 2 variables
//			for (int k = 0; k < sz; k++)
//			{
//				if (val[k] == '0' || val[k] == '1')
//				{
//					temp[k] = val[k] - 48; // converting from ASCII
//				}
//				else
//				{
//					int ind = findProposition(propositions, val[k]); // if it is not 0 or 1 then find the proposition from vector and get the truth value from there
//					temp[k] = propositionsValues[ind][i];
//				}
//				if (neg[k] == '1')
//				{
//					temp[k] = NEGATION(temp[k]); // proposition have negation sign then inverse its truth value
//				}
//			}
//			switch (op) // switch case for operation
//			{
//			case '^':
//				truthTable[i].push_back(AND(temp[0], temp[1]));
//				break;
//			case 'V':
//				truthTable[i].push_back(OR(temp[0], temp[1]));
//				break;
//			case '-':
//				truthTable[i].push_back(IMPLIES(temp[0], temp[1]));
//				break;
//			case '<':
//				truthTable[i].push_back(BICONDITIONAL(temp[0], temp[1]));
//				break;
//			case '~':
//				truthTable[i].push_back(temp[0]); // if negation then simple push value because its negation has already computed
//			default:
//				break;
//			}
//		}
//	}
//	return truthTable; // Returh Truth Table
//}
//
//int findProposition(vector<char> ch, char x)
//{
//	// Function To Find Proposition index
//	for (int i = 0; i < ch.size(); i++)
//	{
//		if (ch[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//int findSubstring(string S1, string S2)
//{
//	int l = 0; //Hold length of second string
//
//	//finding length of second string
//	for (l = 0; S2[l] != '\0'; l++);
//
//	int i, j;
//
//	for (i = 0, j = 0; S1[i] != '\0' && S2[j] != '\0'; i++)
//	{
//		if (S1[i] == S2[j])
//		{
//			j++;
//		}
//		else
//		{
//			i -= j;
//			j = 0;
//		}
//	}
//
//	if (j == l)
//		return i - j;
//	else
//		return -1;
//}
//
//string CorrectBracket(string temp)
//{
//	// Function To Correct The Missing Braces
//	int count = 0;
//	for (int j = 0; j < temp.size(); j++)
//	{
//		if (temp[j] == '(' || temp[j] == '{' || temp[j] == '[') // starting brace increase count by 1
//		{
//			count++;
//		}
//		else if (temp[j] == ')' || temp[j] == '}' || temp[j] == ']') // ending brace decrease count by 1
//		{
//			count--;
//		}
//	}
//	if (count > 0) // count > 0 means closing are less
//	{
//		for (int j = 0; j < count; j++) // push count time closing braces at end of string
//		{
//			temp.push_back(')');
//		}
//	}
//	else if (count < 0) // count < 0 means opening braces are less
//	{
//		count = -count;
//		string t;
//		for (int j = 0; j < count; j++) // push count time opening brace at start of string
//		{
//			t.push_back('(');
//		}
//		t += temp;
//		temp = t;
//	}
//	else
//	{
//		if (temp.find("(") == string::npos && temp.size() >= 3)// if there is no brace then add brace at start and end
//		{
//			string t;
//			t.push_back('(');
//			t += temp;
//			t.push_back(')');
//			temp = t;
//		}
//	}
//
//	if (temp[0] != '~' && ((temp[0] != '(' && temp[0] != '{' && temp[0] != '[') || (temp[temp.size() - 1] != ')' && temp[temp.size() - 1] != '}' && temp[temp.size() - 1] != ']')) && temp.size() >= 3)
//	{
//		// if no starting brace at start or at end means 1 brace pair is missing so add starting and closing brace at end points
//		string t;
//		t.push_back('(');
//		t += temp;
//		t.push_back(')');
//		temp = t;
//	}
//	return temp;
//}
//
//// Boolean Operations
//bool AND(bool A, bool B)
//{
//	return (A && B);
//}
//bool OR(bool A, bool B)
//{
//	return (A || B);
//}
//bool IMPLIES(bool A, bool B)
//{
//	return (!A || B);
//}
//bool BICONDITIONAL(bool A, bool B)
//{
//	return (IMPLIES(A, B) && IMPLIES(B, A));
//	return (A == B);
//}
//bool NEGATION(bool A)
//{
//	return !A;
//}
//
//bool equivalenceChecker(vector<vector<bool>> LTT, vector<vector<bool>> RTT)
//{
//	// check the last column of truth Table if every value is same then its equivalent else not
//	if (LTT.size() == RTT.size())
//	{
//		int Lsz = LTT[0].size() - 1, Rsz = RTT[0].size() - 1;
//		for (int i = 0; i < LTT.size(); i++)
//		{
//			if (LTT[i][Lsz] != RTT[i][Rsz])
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	return false;
//}