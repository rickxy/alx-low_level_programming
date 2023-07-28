section .data
    msg db 'Hello, Holberton', 10 ; The message and newline character

section .text
    global main
    extern printf

main:
    ; Prepare the arguments for printf
    mov rdi, msg ; The format string
    xor rax, rax ; 0 floating point parameters

    ; Call printf
    call printf

    ; Return 0 (success)
    mov eax, 0x60
    xor edi, edi
    syscall
