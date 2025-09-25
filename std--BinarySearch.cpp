#pragma warning (disable: 4786)

#include <algorithm>
#include <iostream>
#include <string>

struct PhoneBook
{
	PhoneBook(std::string s, long num)
	{
		name = s ;
		number = num ;
	}
	PhoneBook() {}
	friend std::ostream& operator<<(std::ostream&, const PhoneBook&) ;
	long number ;
	std::string name ;
} ;

std::ostream& operator<<(std::ostream& os, const PhoneBook& rpb)
{
	os << rpb.name << "\t" << rpb.number << std::endl ;
	return os ;
}

bool compare(const PhoneBook& r1, const PhoneBook& r2)
{
	return (r2.name > r1.name) ;
}

int main()
{
	int Numbers[] = {100, 200, 330, 445, 500} ;
	bool results ;
	int i ;
	std::cout << "Numbers = " ;
	for(i = 0; i < 5; i++)
		std::cout << Numbers[i] << "\t" ;
	std::cout << std::endl ;

	//non-predicate version
	//does 250 exist in the array Numbers?
	results = std::binary_search(Numbers, Numbers+5, 250) ;

	if(results == true)
		std::cout << "250 exists in array Numbers" << std::endl ;
	else
		std::cout << "250 does not exist in array Numbers" << std::endl ;

	//non-predicate version
	//does 445 exist in the array Numbers?
	results = std::binary_search(Numbers, Numbers+5, 445) ;

	if(results == true)
		std::cout << "445 exists in array Numbers" << std::endl ;
	else
		std::cout << "445 does not exist in array Numbers" << std::endl ;

	PhoneBook pb[5] ;
	pb[0] = PhoneBook("Frank", 4651234) ;
	pb[1] = PhoneBook("Jack", 3456218) ;
	pb[2] = PhoneBook("Kevin", 8453445) ;
	pb[3] = PhoneBook("Shaun", 4540082) ;
	pb[4] = PhoneBook("Tom", 8771235) ;

	PhoneBook pb1("Jack", 3456218) ;
	
	std::cout << "Phone Book Entries: " << std::endl ;
	for(i = 0; i < 5; i++)
		std::cout << pb[i] << std::endl ;
	//predicate version
	results = std::binary_search(pb, pb+5, pb1, compare) ;

	if(results == true)
		std::cout << "Jack is listed in the PhoneBook" << std::endl ;
	else
		std::cout << "Jack is not listed in the PhoneBook" << std::endl ;
	return 0 ;
}

/*Program Output

Numbers = 100   200     330     445     500
250 does not exist in array Numbers
445 exists in array Numbers
Phone Book Entries:
Frank   4651234

Jack    3456218

Kevin   8453445

Shaun   4540082

Tom     8771235

Jack is listed in the PhoneBook
*/
