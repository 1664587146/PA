#include "cpu/exec.h"

make_EHelper(test) {
  TODO();

  print_asm_template2(test);
}

make_EHelper(and) {
  TODO();

  print_asm_template2(and);
}

make_EHelper(xor) {
  //TODO();
  rtl_xor(&t0 , &id_src2 -> val , &id_src ->val);
  if(id_dest -> type == OP_TYPE_MEM){
    rtl_sm(&(id_dest-> addr), id_dest -> width , &t0);
  }
  else if(id_dest -> type == OP_TYPE_REG){
    rtl_sr(id_dest-> reg, id_dest -> width , &t0);
  }

  //cf -> t1 and of -> t2
  t1 = t2 = 0;
  rtl_set_CF(&t1);
  rtl_set_OF(&t2);
  rtl_update_ZFSF(&id_dest -> val , id_dest -> width);

  print_asm_template2(xor);
}

make_EHelper(or) {
  TODO();

  print_asm_template2(or);
}

make_EHelper(sar) {
  TODO();
  // unnecessary to update CF and OF in NEMU

  print_asm_template2(sar);
}

make_EHelper(shl) {
  TODO();
  // unnecessary to update CF and OF in NEMU

  print_asm_template2(shl);
}

make_EHelper(shr) {
  TODO();
  // unnecessary to update CF and OF in NEMU

  print_asm_template2(shr);
}

make_EHelper(setcc) {
  uint8_t subcode = decoding.opcode & 0xf;
  rtl_setcc(&t2, subcode);
  operand_write(id_dest, &t2);

  print_asm("set%s %s", get_cc_name(subcode), id_dest->str);
}

make_EHelper(not) {
  TODO();

  print_asm_template1(not);
}

make_EHelper(rol) {
  TODO();
  
  print_asm_template2(rol);
}
