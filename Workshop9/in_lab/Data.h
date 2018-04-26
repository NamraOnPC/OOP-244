// Name :- Namra Fanse
// Student No :- 112219175
// Student Email :- nrfanse@myseneca.ca 
// Workshop 9 in_lab
//Date :- 3/4/2018




#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <iomanip>


namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	template<typename T>
	T max(const T * data, int n){
	    
	    int i;
	    
	    T max = data[0];
	    
	    for (i = 1; i < n; i++ ){
	    
	        if(data[i] >  max){
	    
	            max = data[i];
	    
	        }
	    
	    }
	    
	    return max;
	
	}


	// min returns the smallest item in data
	template<typename T>
	T min(const T * data, int n){
	
	    int i;
	    
	    T min = data[0];
	    
	    for(i = 1 ; i < n ; i++){
	        
	        if(data[i] < min){
	            
	            min = data[i];
	       
	        }
	    
	    }
	    
	    return min;
	}

        
	// sum returns the sum of n items in data
	template<typename T>
	T sum(const T * data, int n){
	    
	    int i;
	    
	    T sum = 0;
	    
	    for(i = 0; i < n ; i++){
	        
	        sum += data[i];
	    
	    }
	    
	    return sum;
	}
   
	// average returns the average of n items in data
    template<typename T>
    double average(const T * data, int n){
        
        return sum(data, n)/n ;
        
    }

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
    template<typename T>
    bool read(std::istream & input, T * data, int n){
        
        for(int i = 0; i < n; i++){
            
            input.ignore();
            
            input >> data[i];
            
            if(input.fail()){
                
                return false;
                
            }
            
        }
        // split input by comma and store them to data
        return true;
    }

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char * name, const T * data, int n){
	    
	    std::cout.width(20);
	    
	    std::cout << std::right << name;
	    
	    for(int i = 0; i < n; i++){
	        
		std::cout.width(15);

		std::cout << data[i];
	        
	    }
	    
	    std::cout << "\n" ; 
	    
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}


#endif
