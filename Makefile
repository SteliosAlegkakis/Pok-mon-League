CXX = g++
CXXFLAGS = -std=c++17

app: app.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f app.exe
