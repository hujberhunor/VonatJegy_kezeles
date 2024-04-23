#ifndef JEGY_H
#define JEGY_H

class Jegy {
private:
  int ar;


public:
  virtual int ar();


};


class Diák : public Jegy{
private:
  char* tipus;
  int kedvezmeny;

public: 

  int getKedv() { return kedvezmeny; }
  
  int ar(){ return ar * kedvezmeny; }

};

// class Kerékpár : public Jegy;










#endif // !JEGY_H
