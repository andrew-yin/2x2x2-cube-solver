#pragma once

#include "color.h"

namespace cubesolver {

class Cube {
 public:
  Cube();
  Cube(Color ful,
       Color fur,
       Color fdl,
       Color fdr,
       Color bul,
       Color bur,
       Color bdl,
       Color bdr,
       Color lur,
       Color lul,
       Color ldl,
       Color ldr,
       Color rul,
       Color rur,
       Color rdl,
       Color rdr,
       Color uur,
       Color uul,
       Color udl,
       Color udr,
       Color dur,
       Color dul,
       Color ddl,
       Color ddr);

  void MoveU();
  void MoveUP();
  void MoveU2();
  void MoveD();
  void MoveDP();
  void MoveD2();
  void MoveL();
  void MoveLP();
  void MoveL2();
  void MoveR();
  void MoveRP();
  void MoveR2();
  void MoveB();
  void MoveBP();
  void MoveB2();
  void MoveF();
  void MoveFP();
  void MoveF2();

 private:
  Color ful_;
  Color fur_;
  Color fdl_;
  Color fdr_;
  Color bul_;
  Color bur_;
  Color bdl_;
  Color bdr_;
  Color lur_;
  Color lul_;
  Color ldl_;
  Color ldr_;
  Color rul_;
  Color rur_;
  Color rdl_;
  Color rdr_;
  Color uur_;
  Color uul_;
  Color udl_;
  Color udr_;
  Color dur_;
  Color dul_;
  Color ddl_;
  Color ddr_;
};

}