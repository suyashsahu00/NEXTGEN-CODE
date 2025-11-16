// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

import "@openzeppelin/contracts/token/ERC721/ERC721.sol";
import "@openzeppelin/contracts/token/ERC721/extensions/ERC721URIStorage.sol";
import "@openzeppelin/contracts/access/Ownable.sol";
import "@openzeppelin/contracts/utils/Counters.sol";

contract NFTMinter is ERC721, ERC721URIStorage, Ownable {
    using Counters for Counters.Counter;
    Counters.Counter private _tokenIdCounter;

    uint256 public mintPrice = 0.001 ether; // Mint price in ETH
    uint256 public maxSupply = 10000;
    
    mapping(uint256 => string) private _tokenNames;
    mapping(uint256 => string) private _tokenDescriptions;
    
    event NFTMinted(
        uint256 indexed tokenId,
        address indexed owner,
        string name,
        string description,
        string tokenURI
    );

    constructor(address initialOwner) ERC721("CustomNFT", "CNFT") Ownable(initialOwner) {
        _tokenIdCounter.increment(); // Start token IDs at 1
    }

    function mintNFT(
        address to,
        string memory name,
        string memory description,
        string memory tokenURI
    ) public payable returns (uint256) {
        require(msg.value >= mintPrice, "Insufficient payment");
        require(_tokenIdCounter.current() <= maxSupply, "Max supply reached");
        require(bytes(name).length > 0, "Name cannot be empty");
        require(bytes(description).length > 0, "Description cannot be empty");
        require(bytes(tokenURI).length > 0, "Token URI cannot be empty");

        uint256 tokenId = _tokenIdCounter.current();
        _tokenIdCounter.increment();

        _safeMint(to, tokenId);
        _setTokenURI(tokenId, tokenURI);
        
        _tokenNames[tokenId] = name;
        _tokenDescriptions[tokenId] = description;

        emit NFTMinted(tokenId, to, name, description, tokenURI);

        return tokenId;
    }

    function getTokenName(uint256 tokenId) public view returns (string memory) {
        require(_exists(tokenId), "Token does not exist");
        return _tokenNames[tokenId];
    }

    function getTokenDescription(uint256 tokenId) public view returns (string memory) {
        require(_exists(tokenId), "Token does not exist");
        return _tokenDescriptions[tokenId];
    }

    function getTotalSupply() public view returns (uint256) {
        return _tokenIdCounter.current() - 1;
    }

    function setMintPrice(uint256 _mintPrice) public onlyOwner {
        mintPrice = _mintPrice;
    }

    function setMaxSupply(uint256 _maxSupply) public onlyOwner {
        maxSupply = _maxSupply;
    }

    function withdraw() public onlyOwner {
        uint256 balance = address(this).balance;
        require(balance > 0, "No funds to withdraw");
        
        (bool success, ) = payable(owner()).call{value: balance}("");
        require(success, "Withdrawal failed");
    }

    // Override required functions
    function tokenURI(uint256 tokenId)
        public
        view
        override(ERC721, ERC721URIStorage)
        returns (string memory)
    {
        return super.tokenURI(tokenId);
    }

    function supportsInterface(bytes4 interfaceId)
        public
        view
        override(ERC721, ERC721URIStorage)
        returns (bool)
    {
        return super.supportsInterface(interfaceId);
    }

    function _burn(uint256 tokenId) internal override(ERC721, ERC721URIStorage) {
        super._burn(tokenId);
    }
}
