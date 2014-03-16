/* 
    Demonstrates usage of phantomjs.
    - when invoked with phantomjs, prints stuff to terminal screen

    Invocation: 

        << phantomjs demo.js >> 

*/

var ry = [1, 3, 5];
console.log('Hi Ellie!');
console.log(ry.length);
for ( var i=0; i < ry.length; i++ ) {
    console.log(ry[i])
}
phantom.exit()
