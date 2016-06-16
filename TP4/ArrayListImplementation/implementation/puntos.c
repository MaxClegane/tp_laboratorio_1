/* usuario: nombre, un nick (que es único), una clave de acceso y mail
. comentarios: identificador de comentario, un texto y un contador de “Me gusta”.

1. ALTAS USUARIO: No es necesario el ingreso de todos los usuarios.
2. MODIFICAR DATOS USUARIO: Se ingresará el Nick del usuario, permitiendomodificar:
• Nombre  • Mail • Clave de acceso
3. BAJA DE USUARIO: Se ingresará el Nick del usuario y se marcara a este como inhabilitado.
4. NUEVO COMENTARIO: El usuario que desee realizar un nuevo comentario deberá ingresar su Nick y su clave de acceso.
5. NUEVO ME GUSTA: El usuario que desee dar me gusta a un comentario deberá ingresar su nick, su clave de acceso y el identificador del comentario.
6. INFORMAR:
1. El usuario con mayor cantidad de comentarios
2. El comentario con mayor cantidad de “Me gusta”
3. El valor promedio de “Me gusta”
7. LISTAR: Realizar un solo listado de los comentarios (mostrando por pantalla el comentario y la cantidad de “Me gusta”) ordenados por los siguientes criterios:
• Nombre de usuario (descendentemente).
• Nick (ascendentemente).
*Se deberá realizar el menú de opciones y las validaciones a través de funciones. Tener en cuenta que no se podrá ingresar a los casos 2, 3, 4 y 5; sin alta de algún usuario.
*1: Se deberá desarrollar una biblioteca lib.c y lib.h la cual contendrá las funciones (Alta, Baja, Modificar, Nuevo comentario, Nuevo Me gusta ,Informar y Listar ).
*2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.

    int     (*add)();                   *
    int     (*len)();                   *
    int     (*contains)();              *
    int     (*set)();                   *
    int     (*remove)();                *
    int     (*clear)();                 *
    int     (*push)();                  *
    int     (*indexOf)();               *
    int     (*isEmpty)();               *
    void*   (*get)();                   *
    void*   (*pop)();                   *
    int     (*containsAll)();           *
    int     (*sort)();                  *
    struct ArrayList* (* clone)();      *
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();       *
*/
