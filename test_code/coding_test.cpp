#include <bits/stdc++.h>

using namespace std;

int add_route(vector<string> airports, vector<vector<string>> routes, string startingAirport)
{
  map<string, string> mp;

  for (vector<string> route : routes)
  {
    if (route[1] == startingAirport)
      continue;
    if (mp.count(route[0]))
    {
      mp[route[1]] = mp.at(route[0]);
    }
    else
    {
      mp[route[1]] = route[0];
    }
  }
  int num = 0;

  for (string airport : airports)
  {
    if (airport == startingAirport)
      continue;
    if (mp[airport] == "" || mp[airport] == airport)
      num++;
  }
  return num;
}

int main()
{
  vector<string> airports = {"BGI", "CDG", "DEL", "DOH", "DSM", "EWR", "EYW", "HND", "ICN", "JFK", "LGA", "LHR", "ORD", "SAN", "SFO", "SIN", "TLV", "BUD"};
  vector<vector<string>> routes = {{"DSM", "ORD"},
                                   {"ORD", "BGI"},
                                   {"BGI", "LGA"},
                                   {"SIN", "CDG"},
                                   {"CDG", "BIN"},
                                   {"CDG", "BUD"},
                                   {"DEL", "DOH"},
                                   {"DEL", "CDG"},
                                   {"TLV", "DEL"},
                                   {"EWR", "HND"},
                                   {"HND", "ICN"},
                                   {"HND", "JFK"},
                                   {"ICN", "JFK"},
                                   {"JFK", "LGA"},
                                   {"EYW", "LHR"},
                                   {"LHR", "SFO"},
                                   {"SFO", "SAN"},
                                   {"SFO", "DSM"},
                                   {"SAN", "EYW"}};
  string startingAirport = "LGA";

  cout << add_route(airports, routes, startingAirport) << endl;
}