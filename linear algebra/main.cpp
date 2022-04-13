//
//  main.cpp
//  linear algebra
//
//  Created by Daniel Clancy on 4/5/22.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>

#define PI 3.14159265

using namespace std;

class LA_Vector {
    private:
        vector<double> vector;
        unsigned long vector_size;
    
        static double deg_sin(double angle) {
            return sin(angle * PI/180);
        }
    
        static double deg_cos(double angle) {
            return cos(angle * PI/180);
        }
    
    

    public:
        LA_Vector(std::vector<double> arr) {
            vector_size = arr.size();
            vector = std::vector<double>();
            vector = arr;

        }
    
        LA_Vector() {
            vector_size = 0;
            vector = std::vector<double>();
        }
    
        LA_Vector operator+(LA_Vector vector2) {
            if(vector_size != vector2.length()) {
                cout << "ERROR: Vectors must be of same size";
                return LA_Vector();
            }
            
            std::vector<double> new_vector_values;
            for(int i = 0; i < vector_size; i++) {
                new_vector_values.push_back(vector.at(i) + vector2.value_at_index(i));
            }
            
            LA_Vector new_vector(new_vector_values);
            return new_vector;
            
        };
    
        LA_Vector operator-(LA_Vector vector2) {
            if(vector_size != vector2.length()) {
                cout << "ERROR: Vectors must be of same size";
                return LA_Vector();
            }
            
            std::vector<double> new_vector_values;
            for(int i = 0; i < vector_size; i++) {
                new_vector_values.push_back(vector.at(i) + vector2.value_at_index(i));
            }
            
            LA_Vector new_vector(new_vector_values);
            return new_vector;
        };
    
        static LA_Vector find_unit_vector_r2(double magnitude, double angle) {
            // Let's do some trig, foo.
            
            // Get the angle down to something usable
            // Check if angle is > 360, loop until it's not!
            while(angle > 360) {
                angle -= 360;
            }
            
            int x_sign;
            int y_sign;
            
            if(angle <= 90) {
                x_sign = 1;
                y_sign = 1;
            } else if (angle <= 180) {
                x_sign = -1;
                y_sign = 1;
                
            } else if (angle <= 270) {
                x_sign = -1;
                y_sign = -1;
            } else {
                x_sign = 1;
                y_sign = -1;
            }
            
            while(angle > 90) {
                angle -= 90;
            }
            
            double x = x_sign * magnitude * deg_cos(angle);
            double y = y_sign * magnitude * deg_sin(angle);

            
            std::vector<double> arr = {x, y};
            
            
            return LA_Vector(arr);
        }
    
        unsigned long length() {
            return vector_size;
        }
    
        double value_at_index(int x) {
            return vector.at(x);
        }
        
        void to_string() {
            
            string output = "(";
            for(int i = 0; i < vector_size; i++) {
                output += std::to_string(vector.at(i));
                if(i != vector_size - 1) {
                    output += ", ";
                }

            }
            output += ")";
            cout << output << endl;
           
        }
};

int main(int argc, const char * argv[]) {
    
    
//    double a[2] = {1, 2};
//    Vector a1(a);
//    a1.to_string();
//
//    double b[2] = {4, 2};
//    Vector a2(b);
//    a2.to_string();
//
//    Vector a3 = a1 + a2;
//    a3.to_string();
//
//    Vector a4 = a2 - a1;
//    a4.to_string();
    LA_Vector v = LA_Vector::find_unit_vector_r2(7, 200);
    LA_Vector w = LA_Vector::find_unit_vector_r2(5, 70);
    
    v.to_string();
    w.to_string();
    
    LA_Vector x = v + w;
    x.to_string();
    
    return 0;
}
