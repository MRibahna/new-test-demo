#include <iostream>
using namespace std;
// Adapter Pattern Example in C++

// Target
class USB {
public:
    virtual void connectWithUSBPort() = 0;
};

// Adaptee
class VGAProjector {
public:
    void connectWithVGAPort() {
        cout << "Connected to projector using VGA port." << endl;
    }
};

// Adapter
class USBtoVGAAdapter : public USB {
private:
    VGAProjector* projector;

public:
    USBtoVGAAdapter(VGAProjector* p) : projector(p) {}

    void connectWithUSBPort() override {
        cout << "USB to VGA Adapter converting signal..." << endl;
        projector->connectWithVGAPort();
    }
};

// Client Code
int main() {
    VGAProjector projector;
    USB* adapter = new USBtoVGAAdapter(&projector);

    adapter->connectWithUSBPort();

    delete adapter;
    return 0;
}
