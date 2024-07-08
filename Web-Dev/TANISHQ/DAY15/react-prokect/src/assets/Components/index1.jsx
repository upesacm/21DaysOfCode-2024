import React , {useState} from 'react';

function LikeButton()
{
    const[count , setCount] = useState(0);
    const[label, setLabel] = useState('Like');


    const handleCLick = () =>
    {
        setCount(count+1);
        setLabel(count ===0 ? 'Like' : '${count} Likes');
    };

    return (
        <div>
            <button onClick={handleCLick}>
                {label}
            </button>

            <span>{count}</span>
        </div>
    );
}

export default LikeButton;