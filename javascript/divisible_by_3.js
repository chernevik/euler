divisible_by_3 = [];
for ( var i = 0; i < 10; i++) {
    if ( i % 3 == 0 ) {
        divisible_by_3.push(i);
    }
};


for ( var i = 0; i < divisible_by_3.length; i++) {
    console.log(divisible_by_3[i]);
};

phantom.exit();

