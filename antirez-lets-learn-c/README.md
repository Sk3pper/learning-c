# Antirez: Let's learn C Course Notes

This section is dedicated to following [@antirez's C programming course](https://www.youtube.com/@antirez).

For each lesson, a new directory will be created. Inside each directory, you'll find a
- `README.md` file with notes, 
- source codes,
- the lesson transcript, and
- other useful materials.

# Index and Status Content

| **Original Title** | **Translated Title** | **Link** | **Status** |
|--------------------|----------------------|----------|------------|
| Impariamo il C: lezione 1 | Learn C: Lesson 1 | [YT-Lesson-1](https://www.youtube.com/watch?v=HjXBXBgfKyk) | ✅ |
| Impariamo il C: lezione 2 | Learn C: Lesson 2 | [YT-Lesson-2](https://www.youtube.com/watch?v=Z84vlG1RRtg) | ToDo |
| Impariamo il C: appendice alla lezione 2: la vita delle variabili locali | Learn C: Appendix to Lesson 2: The Life of Local Variables | [YT-Lesson-2-Bonus](https://www.youtube.com/watch?v=r6mU_IHXEps) | ToDo |
| Impariamo il C: lezione 3 | Learn C: Lesson 3 | [YT-Lesson-3](https://www.youtube.com/watch?v=mw4gUqsGPZw) | ToDo |
| Impariamo il C: lezione 4 | Learn C: Lesson 4 | [YT-Lesson-4](https://www.youtube.com/watch?v=YNsXyasn4R4) | ToDo |
| Impariamo il C: lezione 5 | Learn C: Lesson 5 | [YT-Lesson-5](https://www.youtube.com/watch?v=SWWHqgSwQFw) | ToDo |
| Impariamo il C, lezione 6: IF, GOTO e ricorsione | Learn C, Lesson 6: IF, GOTO and Recursion | [YT-Lesson-6](https://www.youtube.com/watch?v=lc7aYXNl1T8) | ToDo |
| Impariamo il C, lezione 7: ancora sulla ricorsione, l'equivalenza tra while e for, lo switch | Learn C, Lesson 7: More on Recursion, Equivalence Between While and For, Switch | [YT-Lesson-7](https://www.youtube.com/watch?v=HCRthhjbfAg) | ToDo |
| Impariamo il C: lezione 8 (implementiamo il Conway's Game of Life) | Learn C: Lesson 8 (Implementing Conway's Game of Life) | [YT-Lesson-8](https://www.youtube.com/watch?v=c5atNuYdKK8) | ToDo |
| Impariamo il C, lezione 9: Introduzione ai puntatori | Learn C, Lesson 9: Introduction to Pointers | [YT-Lesson-9](https://www.youtube.com/watch?v=BBgZs-jd_QY) | ToDo |
| Impariamo il C, lezione 10: la matematica dei puntatori | Learn C, Lesson 10: Pointer Arithmetic | [YT-Lesson-10](https://www.youtube.com/watch?v=lc7hL9Wt-ho) | ToDo |
| Impariamo il C, lezione 11: chiarimenti sui concetti espressi nella lezione precedente | Learn C, Lesson 11: Clarifications on Concepts from the Previous Lesson | [YT-Lesson-11](https://www.youtube.com/watch?v=msGzuneFpDU) | ToDo |
| Impariamo il C, lezione 12: un primo incontro con malloc() | Learn C, Lesson 12: A First Encounter with malloc() | [YT-Lesson-12](https://www.youtube.com/watch?v=ZkaKwWXJXs8) | ToDo |
| Impariamo il C, lezione 13: il trucco dei metadati nascosti dietro al puntatore | Learn C, Lesson 13: The Hidden Metadata Trick Behind the Pointer | [YT-Lesson-13](https://www.youtube.com/watch?v=9AhaOdEBmPc) | ToDo |
| Impariamo il C, lezione 14: le strutture del C | Learn C, Lesson 14: C Structures | [YT-Lesson-14](https://www.youtube.com/watch?v=p4IMHau2lq8) | ToDo |
| Impariamo il C, lezione 15: le struct del C come mattone delle strutture dati | Learning C, Lesson 15: C Structs as the Building Block of Data Structures | [YT-Lesson-15](https://www.youtube.com/watch?v=aTT2W5NACEY) | ToDo |
| Impariamo il C, lezione 16: le strutture nella nostra libreria delle stringhe col reference counting | Learning C, Lesson 16: Structures in Our String Library with Reference Counting | [YT-Lesson-16](https://www.youtube.com/watch?v=VPs_QtlLNcs) |  ToDo |
| Impariamo il C, lezione 17: ancora sulle strutture, scelte di design sulle stringhe, hexdump() | Learning C, Lesson 17: More on Structures, String Design Choices, Hexdumps | [YT-Lesson-17](https://www.youtube.com/watch?v=grkIJjw6o18) |  ToDo |
| Impariamo il C, lezione 18: la strutture come tipi opachi, typedef, i file con la lib standard | Learning C, lesson 18: structures as opaque types, typedefs, files with the standard lib | [YT-Lesson-18](https://www.youtube.com/watch?v=3w73xjUSUEU) |  ToDo |
| Impariamo il C, puntata 19: le chiamate di sistema | Learning C, lesson 19: System Call | [YT-Lesson-19](https://www.youtube.com/watch?v=QWLJ7CBAu_I) |  To Do |
| Impariamo il C, lezione 20: il buffering della libc e i file mappati in memoria | Learning C, Lesson 20: Libc Buffering and Memory-Mapped Files  | [YT-Lesson-20](https://www.youtube.com/watch?v=yKavhObop5I) |  To Do |
| Impariamo il C, lezione 21: union e bitfield | Learning C, Lesson 21: union and bitfield | [YT-Lesson-21](https://www.youtube.com/watch?v=TM4jgODgdFY) |  To Do |
| Impariamo il C, lezione 22: i puntatori a funzione | Learning C, Lesson 22: pointer to function | [YT-Lesson-22](https://www.youtube.com/watch?v=OIseV5lcx8w) |  To Do |
| Impariamo il C, lezione 23: scriviamo l'interprete Toy Forth (parte 1) | Learning C, Lesson 23: Let's write the interpreter Toy Forth (part 1) | [YT-Lesson-23](https://www.youtube.com/watch?v=vYODKK8TQGE) |  To Do |
| Impariamo il C, lezione 24: l'interprete Toy Forth (parte 2) | Learning C, Lesson 24: the Toy Forth interpreter (part 2) | [YT-Lesson-24](https://www.youtube.com/watch?v=-QxrmHo-V7Y)|  To Do |
| Impariamo il C, lezione 25:: l'interprete Toy Forth (parte 3) | Learning C, Lesson 25: the Toy Forth interpreter (part 3) | [YT-Lesson-25](https://www.youtube.com/watch?v=-1ZhCgaIPOk)|  To Do |
| Impariamo il C, lezione 26: Toy Forth, nei meandri della exec() (parte 4) | Learning C, Lesson 26: Toy Forth, in the depths of exec() (part 4) | [YT-Lesson-26](https://www.youtube.com/watch?v=oMj3N6jYIUU)|  To Do |
| Impariamo il C, lezione 27: Toy Forth, la registrazione delle funzioni (parte 5) | Learning C, Lesson 26: Toy Forth, Recording Functions (Part 5) | [YT-Lesson-27](https://www.youtube.com/watch?v=C4AHEK3fSjg)|  To Do |
| Impariamo il C: approfondimento sul reference counting | Learning C: A Deep Dive into Reference Counting | [YT-Lesson-In-Depth-Analysis](https://www.youtube.com/watch?v=QdZc1JV_oCw)|  To Do |
| Impariamo il C, lezione 28: le funzioni con un numero variabile di argomenti | Learning C, Lesson 28: functions with a variable number of arguments | [YT-Lesson-28](https://www.youtube.com/watch?v=cvWbCx0lLjs)|  To Do |
| Impariamo il C, lezione 29: Toy Forth, esecuzione del primo semplice programma | Learning C, Lesson 29: Toy Forth, running the first simple program| [YT-Lesson-29](https://www.youtube.com/watch?v=nHzlRqPnlrE)|  To Do |
| Impariamo il C, lezione 30: Sviluppo di un'immagine per lo ZX Spectrum (Parte 1) | Learning C, Lesson 30: Evolving an Image for the ZX Spectrum (Part 1) | [YT-Lesson-30](https://www.youtube.com/watch?v=D1U3uCe)|  To Do |
| Impariamo il C, lezione 31: Sviluppo di un'immagine per lo ZX Spectrum (Parte 2) | Learning C, Lesson 31: Evolving an Image for the ZX Spectrum (Part 2) | [YT-Lesson-31](https://www.youtube.com/watch?v=fZmdsh0gQig)|  To Do |
| Impariamo il C, lezione 31 - Appendix:  | Learning C, Lesson 31: Appendix to lesson 31 of the C programming course | [YT-Lesson-31-Appnedix](https://www.youtube.com/watch?v=xaEr-XSlWfo)|  To Do |
| Impariamo il C, lezione 32: rudimenti di grafica 3D  | Learning C, Lesson 32: rudiments of 3D graphics | [YT-Lesson-32](https://www.youtube.com/watch?v=4EofabMH41M)|  To Do |
| Impariamo il C, puntata speciale: come riesumare gli algoritmi dalla memoria senza la documentazione | Learn C, Special Episode: How to Resurrect Algorithms from Memory Without Documentation | [YT-Special](https://www.youtube.com/watch?v=soiBgJjAmP8) | To Do |
| Random variables | Random Variables | [YT-Bonus](https://www.youtube.com/watch?v=HzBqda0Jg3E) | To Do | -->


**Creator**: Salvatore Sanfilippo [@antirez]  <br>
**Series**: "Impariamo il C" (Learning C Programming) <br>
**Total Videos**: 34 <br>
**Playlist Link**: [Playlist Link](https://www.youtube.com/watch?v=p4IMHau2lq8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=1) <br>
**Description** This is a comprehensive C programming tutorial series covering topics from basic syntax to advanced concepts like pointers, memory management with malloc(), and data structures. <br>

