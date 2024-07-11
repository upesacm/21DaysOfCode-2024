import React from "react";

const GreetWeb = ({username}) => {
    return(
        <div>
            {username ? <h1>hello {username}, have a good day!</h1> : <h1>Hello ,People! </h1>}

        </div>

    );
   
};
export default GreetWeb;