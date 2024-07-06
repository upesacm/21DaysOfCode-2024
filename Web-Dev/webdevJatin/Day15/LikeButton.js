import React, { useState } from 'react';

function LikeButton() {
    const [count, setCount] = useState(0);

    return (
        <div>
            <button onClick={() => setCount(count + 1)}>Like</button>
            <span>{count}</span>
        </div>
    );
}

export default LikeButton;
