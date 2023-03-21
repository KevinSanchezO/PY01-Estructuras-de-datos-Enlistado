# PY01-Estructuras-de-datos-Enlistado
Proyecto programado para el curso de estructuras de datos en el segundo semestre del 2020 desarrollado en C++
## Implementación

<p>La aplicación maneja múltiples estructuras lineales con atributos de comportamiento distintos y cuyos nodos pueden almacenar información dinámica (es decir, configurable por el usuario) que puede ser distinta para cada una de ellas.</p>

<p>El usuario puede definir conjuntos de datos denominados elementos, estos deben tener un identificador, un nombre y una lista de atributos que se pueden almacenar en el momento de creación (o instanciación) de uno de ellos. Los identificadores son manejados internamente por la aplicación y no son editables. Cada atributo de la lista debe tener las siguientes características:</p>

<ul>
 <li>Tipo de dato: puede ser numérico (únicamente enteros), alfanumérico (cadenas o simples), fecha, hora o booleano</li>
 <li>Tamaño máximo: de 1 a n cualquier número entero del máximo de datos almacenables asociados en el atributo</li>
 <li>Modo de acceso: rw (lectura y escritura) o r (sólo lectura)</li>
</ul>

<p>El programa permite realizar las siguientes acciones con las estructuras internas:</p>

<table style="width:100%">
  <tr>
    <td>Función</td>
    <td>Descripción</td>
  </tr>
  <tr>
    <td>Crear elemento</td>
    <td>Tras obtener los datos necesarios para hacerlo, crea un nuevo elemento en el sistema, disponible para la creación de estructuras que almacenen este tipo de     datos.</td>
  </tr>
  
  <tr>
  <td>Visualizar elementos</td>
  <td>Muestra información de todos los elementos creados en el sistema, que se encuentran disponibles para su utilización (en una o varias estructuras de datos)</td>
  </tr>
  
  <tr>
  <td>Crear estructura</td>
  <td>Solicita el nombre, tipo de estructura, tipo de elemento y atributos de la estructura lineal por utilizar. Se agrega una estructura vacía, con el tipo de datos indicados, al programa, sin perder acceso a cualquier otra preexistente, y comportamiento solicitados por el usuario</td>
  </tr>
  
  <tr>
  <td>Utilizar estructura</td>
  <td>Se despliega un submenú con las opciones de uso de una estructura, disponibles según su tipo y atributos, detallados más adelante</td>
  </tr>
  
  <tr>
  <td>Visualizar estructura</td>
  <td>Muestra todos los elementos asociados a una estructura de datos particular y su estado actual en seguimiento a su tipo de comportamiento y atributos.</td>
  </tr> 
  
  <tr>
  <td>Eliminar estructura</td>
  <td>Borra una estructura vacía del sistema, si la estructura que se solicita borrar no está vacía se indica error en el procesamiento.</td>
  </tr>
  
  <tr>
  <td>Estado</td>
  <td>Imprime información de resumen sobre el estado general del programa.</td>
  </tr>
</table>

<p>Los tipos de estructuras permitidas son: listas, pilas y colas.</p>
<p>Los atributos opcionales a elegir en caso aplicable son: enlazamiento entre elementos, circularidad de la estructura, tipo de inserción en la lista (inicio, final, ordenado o aleatorio)</p>
<p>Las operaciones de uso de la estructura, son: insertar, buscar, ordenar y eliminar; cada una de ellas con los nombres que corresponden al tipo de estructura definida.</p>
