friend istream &operator>>(istream &is, Employee &e) {
    is >> e.id >> e.age >> e.name;
    return is;
}

int main() {
    Employee e1(0, 0, ""), e2(0, 0, "");
    cout << "Enter details for Employee 1 (ID Age Name): ";
    cin >> e1;
    cout << "Enter details for Employee 2 (ID Age Name): ";
    cin >> e2;

    cout << "\nBefore Swap:\n";
    cout << e1 << endl;
    cout << e2 << endl;

    e1.swap(e2);

    cout << "\nAfter Swap:\n";
    cout << e1 << endl;
    cout << e2 << endl;

    return 0;
}
