#include<iostrem>
#include<fstream>
using namespace std;
main_program{
    int n;
    cout << "n = ? ";
    cin >> n;

    float a, b, t;
    cout << "Enter step size for time: ";
    cin >> t;
    cout << "Enter rate parameters a and b: ";
    cin >> a >> b;

    float S[n+1], I[n+1];
    cout << "Initial Infected Population I0 = ? ";
    cin >> I[0];
    cout << "Initial Susceptible Population S0 = ? ";
    cin >> S[0];

    cout << "Susceptible population - " << endl;
    for(int j = 0; j < n && S[j] > 0 && I[j] > 0; j++) {
        // Calculate RK4 increments
        float k1 = t * (-a * S[j] * I[j]);
        float l1 = t * (a * S[j] * I[j] - b * I[j]);

        float k2 = t * (-a * (S[j] + k1/2) * (I[j] + l1/2));
        float l2 = t * (a * (S[j] + k1/2) * (I[j] + l1/2) - b * (I[j] + l1/2));

        float k3 = t * (-a * (S[j] + k2/2) * (I[j] + l2/2));
        float l3 = t * (a * (S[j] + k2/2) * (I[j] + l2/2) - b * (I[j] + l2/2));

        float k4 = t * (-a * (S[j] + k3) * (I[j] + l3));
        float l4 = t * (a * (S[j] + k3) * (I[j] + l3) - b * (I[j] + l3));

        // Update S and I
        S[j+1] = S[j] + (k1 + 2*k2 + 2*k3 + k4) / 6;
        I[j+1] = I[j] + (l1 + 2*l2 + 2*l3 + l4) / 6;

        // Output results
        cout << S[j] << endl;
    }

    cout << "Infected population - " << endl;
    for(int j = 0; j < n && S[j] > 0 && I[j] > 0; j++) {
        cout << I[j] << endl;

    }
    cout << "Recovered population - " << endl;
    for(int j = 0; j < n && S[j] > 0 && I[j] > 0; j++) {
        cout << S[0] + I[0] - S[j] - I[j] << endl;

    }

}
int p,i;
cout<<"eneter no of data pts.";
cin>>p;
i = 0;
float a,b,A[p+2],B[p+2],t;
cout<<"eneter step size for time";
cin>>t;
cout<<"enter susceptible pop.";
while(i < p){
cin>>A[i];
i = i+1;
}
i = 0;
cout<<"enter infected pop.";
while(i < p){
cin>>B[i];
i = i+1;
}
i = 0;
a = 0;
b = 0;
while(i < p-1){
a = a + (A[i] - A[i+1])/(A[i]*B[i]*t);
b = b + (A[i] - A[i+1] + B[i] - B[i+1])/(B[i]*t);
i = i+1;
}
i = 0;
cout<<endl;
cout<<"a ≈ "<<a/(p-1)<<endl;
cout<<"b ≈ "<<b/(p-1)<<endl;
float u = a/(p-1);
float o,q;
float v = b/(p-1);
o = 0;
q = 0;
while(i < p-1){
o = o + (((A[i] - A[i+1])/(A[i]B[i]*t)) - u)(((A[i] - A[i+1])/(A[i]*B[i]*t)) - u);
q = q + (((A[i] - A[i+1] + B[i] - B[i+1])/(B[i]t)) - v)(((A[i] - A[i+1] + B[i] - B[i+1])/(B[i]*t)) - v);
i = i+1;
}
cout<<"Standard error in 'a' ≈ "<<sqrt(o/(p-2))/sqrt(p-1)<<endl;
cout<<"Standard error in b ≈ "<<sqrt(q/(p-2))/sqrt(p-1)<<endl;
}