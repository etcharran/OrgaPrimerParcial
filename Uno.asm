extern free
extern malloc

%define loc_of 0
%define vis_of 4
%define desc_of 8
%define sig_of 16
%define tam 24

global Borrado
Borrado:
push rbp
mov rbp,rsp

mov rbx,rdi; Tengo puntero a puntero



pop rbp