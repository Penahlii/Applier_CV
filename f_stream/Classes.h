#pragma once

class Applier
{
	string name;
	ushort age;
	string speciality;
	string text;

public:

	// Constructors

	Applier(string name, ushort age, string speciality, string text)
	{
		this->set_name(name);
		this->set_age(age);
		this->set_speciality(speciality);
		this->set_text(text);
	}

	// Set Methods

	void set_name(string name)
	{
		if (name.length() >= 3)
			this->name = name;
		else
			throw InvalidArugmentException("Invalid Name Length", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_age(ushort age)
	{
		if (age > 18 && age <= 65)
			this->age = age;
		else
			throw InvalidArugmentException("Invalid Age", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_speciality(string speciality)
	{
		if (speciality.length() >= 3)
			this->speciality = speciality;
		else
			throw InvalidArugmentException("Invalid Speciality Length", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void set_text(string text)
	{
		if (text.length() >= 5)
			this->text = text;
		else
			throw InvalidArugmentException("Invalid Text Length", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	// Get Methods

	inline string get_name() const { return  this->name; }
	inline int get_age() const { return this->age; }
	inline string get_speciality() const { return this->speciality; }
	inline string get_text() const { return this->text; }

	// Show

	void show() const
	{
		cout << "Name: " << this->name << endl; 
		cout << "Age: " << this->age << endl;
		cout << "Speciality: " << this->speciality << endl;
		cout << "Text: " << this->text << endl;
	}

	// Get All

	inline string get_all() const { return (this->name + " " + to_string(this->age) + " " + this->speciality + " " + this->text + "\n"); }

	// cout

	friend ostream& operator<<(ostream& os, const Applier& applier);
	friend ostream& operator<<(ostream& os, const Applier* applier);
};

// cout

ostream& operator<<(ostream& os, const Applier& applier)
{
	applier.show();

	return os;
}

ostream& operator<<(ostream& os, const Applier* applier)
{
	applier->show();

	return os;
}

class Company
{
	vector<Applier*> appliers;

public:

	void hire_up(Applier* new_cv) { appliers.push_back(new_cv); }

	void show_all_cv()
	{
		if (appliers.size() == 0)
		{
			cout << "There is Not Any CVs yet";
			return;
		}
		for (size_t i = 0; i < appliers.size(); i++)
		{
			appliers[i]->show();
		}
		cout << endl;
	}

	void write_to_file(string filename)
	{
		ofstream file(filename);
		if (file.is_open())
		{
			for (size_t i = 0; i < appliers.size(); i++)
				file << appliers[i]->get_all();
			file.close();
		}
		else
			throw InvalidArugmentException("Invalid FILE", __DATE__, __TIME__, __FILE__, __LINE__);
	}

	void read_to_file(string filename)
	{
		ifstream file(filename);
		if (file.is_open())
		{
			string name, speciality, text;
			ushort age;
			do
			{
				file >> name;
				if (file.eof())
				{
					file >> age;
					file >> speciality;
					getline(file, text);

					Applier* new_cv = new Applier(name, age, speciality, text);
					this->appliers.push_back(new_cv);
				}
			} while (!file.eof() && name.length() >= 1);
		}
		else
			throw InvalidArugmentException("Invalid FILE", __DATE__, __TIME__, __FILE__, __LINE__);
		file.close();
	}
};