import { useState } from "react";

export const Name = () => {
    const [name, setName] = useState("John");

    const updateName=()=> {
        setName("Jane");
    }

    return(
        <div>
            <p>{name}</p>
            <button onClick={updateName}>
                Update name
            </button>

        </div>
    );
};