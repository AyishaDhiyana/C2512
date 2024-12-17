int main() {
    int N;
    cout << "Enter number of programmers: ";
    cin >> N;

    unique_ptr<Programmer[]> programmers = make_unique<Programmer[]>(N);

    for (int i = 0; i < N; ++i) {
        cout << "Enter details for Programmer " << (i + 1) << " (ID Age Name TaskCount Tasks): ";
        cin >> programmers[i];
    }

    cout << "\nProgrammer Details:\n";
    for (int i = 0; i < N; ++i) {
        cout << programmers[i] << endl;
    }

    return 0;
}
