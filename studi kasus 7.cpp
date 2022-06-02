#include <iostream>

using namespace std;
class urut{
  friend istream& operator>>(istream& in, urut& a);
	friend ostream& operator<<(ostream& out, urut& a);
  public :
    void urutan();
    void nyari();

  private :
  void ngurut(int, int, int&);
		void penukaran(int*, int* );
		void penukaran1(string*, string* );
		int data[10],n,low,high; 
    	string nama[20];
    
};
void urut::ngurut(int dari,int n, int &tempat)
{
	int min = data[dari];
	string min1 =nama[dari];
	tempat = dari;
	for( int i=dari+1; i<n ;i++){
	if(data[i]<min){
		min=data[i];
		min1=nama[i];
		tempat=i;
		}	
	}
}
void urut::penukaran(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void urut::penukaran1(string *a, string *b){
	string temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void urut::urutan(){
	int t;
	for(int i= 0; i<n; i++){
		ngurut( i , n , t );
		penukaran( &data[i], &data[t] );
		penukaran1( & nama[i], &nama[t]);
		
		cout<<"======================\n";
		cout<<"nim : "<<data[i]<<endl;
		cout<<"nama: "<<nama[i]<<endl;
		cout<<"======================\n";
	}
  
}
void urut::nyari(){
	int nyary;
	cin>>nyary;
	for (int i=0;i<n;i++){
	if(nyary==data[i]){
			cout<<"hasil = \nnama = "<<nama[i]<<endl<<"nim = "<<data[i];
	}
	
	}
		
}


istream& operator >> (istream& in, urut& a){
  cout<<"tentukan banyak data : ";
  int n;
	in>>a.n;
	for(int i= 0; i<a.n;i++){
		cout<<"masukkan nama mahasiswa "<<i<<" : ";
		cin>>a.nama[i];
    cout<<"masukkan nim mahasiswa"<<i<<" : ";
    cin>>a.data[i];
    cout<<"===========================\n";
	}
	cout<<"data setelah diurutkan : \n";
	a.urutan();
	cout<<"cari nim : \n";
	a.nyari();
	
	return in;
}
int main(){
	urut run;
	cin>>run;
}
