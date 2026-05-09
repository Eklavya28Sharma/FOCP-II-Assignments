#include <iostream>
#include <map>
#include <set>
using namespace std;

class MovieTicket {
    map<int, int> avail;
    map<int, set<int>> bookings;
    const int MAX = 100;

public:
    bool book(int c, int m) {
        if (avail.find(m) == avail.end()) avail[m] = MAX;
        if (bookings[m].count(c)||avail[m] == 0) return false; // if both the count and availibility are matching the condition they will besent to false
        bookings[m].insert(c); avail[m]--;
        return true; // if the other condition matches or being different to the false condition it will return true in all the cases
    }
    bool cancel(int c, int m) {
        if (!bookings[m].count(c)) return false; // customer has not booked the ticket and it will be retuning false 
        bookings[m].erase(c); avail[m]++;
        return true;   // the ticket is marked as canceled and it will be returning true value
    }
    bool isBooked(int c, int m)       { return bookings[m].count(c) > 0; } // even if the person has queries it will be neglected because the slot is already booked 
    int  getAvail(int m)              { return avail.count(m) ? avail[m] : MAX; } // the user would be getting a canceled ticket or the seat available to the other one
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    MovieTicket mt;
    int Q; cin >> Q;
    while (Q--) {
        string q; cin >> q;
        if (q == "BOOK")              { int x,y; cin>>x>>y; cout<<(mt.book(x,y)?"true":"false")<<"\n"; }
        else if (q == "CANCEL")       { int x,y; cin>>x>>y; cout<<(mt.cancel(x,y)?"true":"false")<<"\n"; }
        else if (q == "IS_BOOKED")    { int x,y; cin>>x>>y; cout<<(mt.isBooked(x,y)?"true":"false")<<"\n"; }
        else if (q == "AVAILABLE_TICKETS") { int y; cin>>y; cout<<mt.getAvail(y)<<"\n"; }
    }
    return 0; // return will be available 
}