// 202401040027 Paras Satpute

#include <iostream>
using namespace std;
#define N 5

class Item {
public:
  int id, qty;
  float price;
};

class Deque {
  Item a[N];
  int f, r;

public:
  Deque() { f = r = -1; }

  bool full() { return (f == 0 && r == N - 1) || (f == r + 1); }
  bool empty() { return f == -1; }

  void insertFront(Item x) {
    if (full()) {
      cout << "Deque Full.\n";
      return;
    }
    if (empty())
      f = r = 0;
    else if (f == 0)
      f = N - 1;
    else
      f--;
    a[f] = x;
    cout << "Added at Front.\n";
  }

  void insertRear(Item x) {
    if (full()) {
      cout << "Deque Full.\n";
      return;
    }
    if (empty())
      f = r = 0;
    else if (r == N - 1)
      r = 0;
    else
      r++;
    a[r] = x;
    cout << "Added at Rear.\n";
  }

  void delFront() {
    if (empty()) {
      cout << "Nothing to remove.\n";
      return;
    }
    cout << "Removed Front Item.\n";
    if (f == r)
      f = r = -1;
    else
      f = (f + 1) % N;
  }

  void delRear() {
    if (empty()) {
      cout << "Nothing to remove.\n";
      return;
    }
    cout << "Removed Rear Item.\n";
    if (f == r)
      f = r = -1;
    else if (r == 0)
      r = N - 1;
    else
      r--;
  }

  void display() {
    if (empty()) {
      cout << "Deque is Empty.\n";
      return;
    }
    cout << "\nCurrent Items:\n";
    int i = f;
    while (true) {
      cout << "ID:" << a[i].id << " | Qty:" << a[i].qty
           << " | Price:" << a[i].price << "\n";
      if (i == r)
        break;
      i = (i + 1) % N;
    }
  }
};

int main() {
  Deque d;
  Item x;
  int ch, m;
  cout << "*** DEQUE INVENTORY SYSTEM ***\n";
  while (true) {
    cout << "\n1.Input-Restricted Mode\n2.Output-Restricted "
            "Mode\n3.Exit\nChoose: ";
    cin >> m;
    if (m == 1) {
      while (true) {
        cout << "\n1.Add at Rear\n2.Remove Front\n3.Remove Rear\n4.Show "
                "Items\n5.Back\nChoose: ";
        cin >> ch;
        if (ch == 1) {
          cout << "Enter ID Qty Price: ";
          cin >> x.id >> x.qty >> x.price;
          d.insertRear(x);
        } else if (ch == 2)
          d.delFront();
        else if (ch == 3)
          d.delRear();
        else if (ch == 4)
          d.display();
        else
          break;
      }
    } else if (m == 2) {
      while (true) {
        cout << "\n1.Add at Front\n2.Add at Rear\n3.Remove Front\n4.Show "
                "Items\n5.Back\nChoose: ";
        cin >> ch;
        if (ch == 1) {
          cout << "Enter ID Qty Price: ";
          cin >> x.id >> x.qty >> x.price;
          d.insertFront(x);
        } else if (ch == 2) {
          cout << "Enter ID Qty Price: ";
          cin >> x.id >> x.qty >> x.price;
          d.insertRear(x);
        } else if (ch == 3)
          d.delFront();
        else if (ch == 4)
          d.display();
        else
          break;
      }
    } else
      break;
  }
  cout << "\nThank you!\n";
}
