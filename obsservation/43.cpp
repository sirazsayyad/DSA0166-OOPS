#include <iostream>
#include <conio.h>
#include <dos.h>

int interupt (*oldMouseInterrupt)(...);

void interrupt newMouseInterrupt(...) {
    _asm {
        // Save registers
        push ax
        push bx
        push cx
        push dx
        push es
        push di
        push si

        // Call old mouse interrupt
        call oldMouseInterrupt

        // Get mouse position and button status
        mov ax, 3
        int 0x33
        // mouse status in bx, x in cx, y in dx
        mov [mouseX], cx
        mov [mouseY], dx
        mov [mouseButton], bx

        // Restore registers
        pop si
        pop di
        pop es
        pop dx
        pop cx
        pop bx
        pop ax
    }
}

int main() {
    // Save old mouse interrupt vector
    oldMouseInterrupt = getvect(0x33);
    // Set new mouse interrupt vector
    setvect(0x33, newMouseInterrupt);

    // Enable mouse
    _asm {
        mov ax, 0
        int 0x33
    }

    while (!kbhit()) {
        std::cout << "Mouse X: " << mouseX << " Mouse Y: " << mouseY << " Mouse Button: " << mouseButton << std::endl;
        delay(100);
    }

    // Restore old mouse interrupt vector
    setvect(0x33, oldMouseInterrupt);
    return 0;
}
