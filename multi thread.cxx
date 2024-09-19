#include <iostream>
#include <thread>
using namespace std;

bool isFinished = false;

void DoWork(){
    int i = 0;
    while( 0 < 200){
        
        //prints thread id
            cout << "started thread id=" << this_thread::get_id() << "working... " << i << "\n";
			i++;
     }
    return;
}

int main(int argc, char *argv[])
{
	thread worker(DoWork);
	
	cin.get();
	isFinished = true;
	
	//wait for worker thread to finish
	worker.join();
	
	//prints thread id
	cout << "started thread id=" << this_thread::get_id() << endl;
	
	cin.get();
	
}
