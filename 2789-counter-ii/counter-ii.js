var createCounter = function(init) {
    let current = init;

    const obj = {
        increment: function() {
            return ++current;
        },
        decrement: function() {
            return --current;
        },
        reset: function() {
            current = init;
            return current;
        }
    };

    return obj;
};
