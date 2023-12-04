#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)

class FacebookPost
{
	unsigned int reactions[7]{ 0 };
	char description[1024];
	char photoPath[32];

public:

	std::ifstream& operator<< (const char* path)
	{
		std::ifstream photo(path);
		
		char buffer[1024];

		while (photo)
		{
			photo >> buffer;
			std::cout << buffer << std::endl;
		}

		return photo;
	}

	void addReaction(int indexOfReaction)
	{
		if (indexOfReaction < 0 || indexOfReaction > 6 )
		{
			std::cerr << "You have entered incorrect index for reaction! \n";
			return;
		}

		reactions[indexOfReaction]++;
	}

	void printPost()
	{
		std::cout << description << " " << photoPath << " ";

		for (size_t i = 0; i < 7; i++)
		{
			std::cout << reactions[i] << " ";
		}

		std::cout << std::endl;
	}

	void copyPost(const FacebookPost& post)
	{
		for (size_t i = 0; i < 7; i++)
		{
			reactions[i] = post.reactions[i];
		}

		strcpy(description, post.description);
		strcpy(photoPath, post.photoPath);
	}

	int getSumOfReactions()
	{
		int sum = 0;

		for (size_t i = 0; i < 7; i++)
		{
			sum += reactions[i];
		}

		return sum;
	}
};

class FacebookProfile
{
	char* name;
	FacebookPost** posts;
	unsigned int numberOfPosts;

	void free()
	{
		delete[] name;
		name = nullptr;

		for (size_t i = 0; i < numberOfPosts; i++)
		{
			delete[] posts[i];
			posts[i] = nullptr;
		}

		delete[] posts;
		posts = nullptr;

		numberOfPosts = 0;
	}

	void copyFrom(const FacebookProfile& profile)
	{
		name = new char[strlen(profile.name) + 1];
		strcpy(name, profile.name);

		posts = new FacebookPost * [profile.numberOfPosts];
		numberOfPosts = profile.numberOfPosts;

		for (unsigned int i = 0; i < numberOfPosts; i++)
		{
			addPostAtIndex(*profile.posts[i], i);
		}
	}

public:

	FacebookProfile()
	{
		name = nullptr;
		posts = nullptr;
		numberOfPosts = 0;
	}

	FacebookProfile(const char* inputName, unsigned int inputNumberOfPosts)
	{
		name = new char[strlen(inputName) + 1];
		strcpy(name, inputName);

		posts = new FacebookPost * [inputNumberOfPosts] {nullptr};

		numberOfPosts = inputNumberOfPosts;
	}

	FacebookProfile(const FacebookProfile& profile)
	{
		copyFrom(profile);
	}

	FacebookProfile& operator= (const FacebookProfile& profile) noexcept
	{
		if (this != &profile)
		{
			free();
			copyFrom(profile);
		}
		return *this;
	}

	FacebookProfile(FacebookProfile&& profile) noexcept
	{
		name = profile.name;
		profile.name = nullptr;

		posts = profile.posts;
		profile.posts = nullptr;

		numberOfPosts = profile.numberOfPosts;
	}

	~FacebookProfile()
	{
		free();
	}

	void addPostAtIndex(const FacebookPost& post,unsigned int index)
	{
		if (index > numberOfPosts)
		{
			std::cerr << "You have entered incorrect index \n";
		}

		posts[index]->copyPost(post);
	}

	int operator[] (unsigned int index)
	{
		if (posts[index] == nullptr)
		{
			throw std::runtime_error("There is no post with this index! \n");
		}

		return posts[index]->getSumOfReactions();
	}

	bool isEmpty(unsigned int index)
	{
		return posts[index] == nullptr;
	}

};

int main()
{

	return 0;
}