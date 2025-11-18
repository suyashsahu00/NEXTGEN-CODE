# NFT Minting DApp

A modern, full-stack decentralized application for minting NFTs on Ethereum and Polygon networks. Built with Next.js, TypeScript, Tailwind CSS, and Hardhat.

## Features

- 🎨 **Easy NFT Minting**: Simple interface for creating NFTs with name, description, and image
- 🔗 **Multi-Chain Support**: Deploy on Ethereum Sepolia testnet or Polygon networks
- 💰 **Configurable Pricing**: Set custom mint prices and supply limits
- 🔐 **Wallet Integration**: Connect with MetaMask and other wallets via RainbowKit
- 📱 **Responsive Design**: Mobile-friendly interface with Tailwind CSS
- 🔍 **Block Explorer Integration**: Direct links to view transactions and NFTs
- ⚡ **Real-time Updates**: Live transaction status and confirmations
- 🛡️ **Error Handling**: Comprehensive error handling and user feedback

## Tech Stack

### Frontend
- **Next.js 14** - React framework with App Router
- **TypeScript** - Type-safe development
- **Tailwind CSS** - Utility-first CSS framework
- **RainbowKit** - Wallet connection library
- **Wagmi** - React hooks for Ethereum
- **Viem** - TypeScript interface for Ethereum
- **React Hot Toast** - Toast notifications

### Smart Contract
- **Solidity ^0.8.19** - Smart contract language
- **Hardhat** - Development environment
- **OpenZeppelin** - Secure contract libraries
- **ERC721** - NFT standard implementation

## Project Structure

```
nft-minting-app/
├── contracts/              # Smart contracts
│   └── NFTMinter.sol       # Main NFT contract
├── scripts/                # Deployment scripts
│   └── deploy.js          # Contract deployment
├── app/                    # Next.js app directory
│   ├── components/         # React components
│   ├── lib/               # Utility libraries
│   ├── globals.css        # Global styles
│   ├── layout.tsx         # Root layout
│   └── page.tsx           # Home page
├── hardhat.config.js      # Hardhat configuration
├── next.config.js         # Next.js configuration
├── tailwind.config.js     # Tailwind configuration
└── package.json           # Dependencies and scripts
```

## Getting Started

### Prerequisites

- Node.js 18+ 
- npm or yarn
- MetaMask or compatible wallet
- Alchemy API key (for RPC endpoints)

### Installation

1. **Clone and install dependencies:**
```bash
cd nft-minting-app
npm install
```

2. **Set up environment variables:**
```bash
cp .env.example .env.local
```

Edit `.env.local` with your configuration:
```env
# Blockchain Configuration
NEXT_PUBLIC_CHAIN_ID=11155111
NEXT_PUBLIC_CONTRACT_ADDRESS=your_deployed_contract_address

# Alchemy API URLs
ALCHEMY_SEPOLIA_URL=https://eth-sepolia.g.alchemy.com/v2/YOUR_API_KEY
ALCHEMY_POLYGON_URL=https://polygon-mainnet.g.alchemy.com/v2/YOUR_API_KEY

# Private Key for Deployment (DO NOT COMMIT)
PRIVATE_KEY=your_private_key_here

# API Keys for Contract Verification
ETHERSCAN_API_KEY=your_etherscan_api_key
POLYGONSCAN_API_KEY=your_polygonscan_api_key
```

### Smart Contract Deployment

1. **Compile the contract:**
```bash
npm run compile
```

2. **Deploy to Sepolia testnet:**
```bash
npm run deploy
```

3. **Deploy to local Hardhat network:**
```bash
# Terminal 1: Start local node
npm run node

# Terminal 2: Deploy to local network
npm run deploy-local
```

4. **Update contract address:**
After deployment, update `NEXT_PUBLIC_CONTRACT_ADDRESS` in your `.env.local` file with the deployed contract address.

### Frontend Development

1. **Start the development server:**
```bash
npm run dev
```

2. **Open your browser:**
Navigate to `http://localhost:3000`

3. **Connect your wallet:**
- Install MetaMask or compatible wallet
- Switch to Sepolia testnet
- Get test ETH from [Sepolia faucet](https://sepoliafaucet.com/)
- Connect wallet to the application

## Smart Contract Details

### NFTMinter Contract Features

- **ERC721 Standard**: Full NFT functionality
- **Ownable**: Owner-only administrative functions
- **URI Storage**: Metadata storage for each NFT
- **Configurable Pricing**: Adjustable mint price
- **Supply Management**: Maximum supply limits
- **Metadata Storage**: On-chain name and description storage

### Key Functions

```solidity
// Mint a new NFT
function mintNFT(
    address to,
    string memory name,
    string memory description,
    string memory tokenURI
) public payable returns (uint256)

// Get mint price
function mintPrice() public view returns (uint256)

// Get total supply
function getTotalSupply() public view returns (uint256)

// Owner functions
function setMintPrice(uint256 _mintPrice) public onlyOwner
function withdraw() public onlyOwner
```

## Usage Guide

### Minting an NFT

1. **Connect Wallet**: Click "Connect Wallet" and select your wallet
2. **Fill Form**: Enter NFT name, description, and upload image
3. **Review**: Check mint price and transaction details
4. **Mint**: Click "Mint NFT" and confirm transaction
5. **Confirmation**: View transaction on block explorer

### Viewing Your NFTs

After minting, you can:
- View transaction on Etherscan/Polygonscan
- See NFT on OpenSea (testnet or mainnet)
- Check ownership in your wallet

## Configuration

### Network Configuration

The app supports multiple networks configured in `hardhat.config.js`:

- **Sepolia Testnet** (Chain ID: 11155111)
- **Polygon Mainnet** (Chain ID: 137)
- **Local Hardhat** (Chain ID: 1337)

### Customization

1. **Contract Parameters:**
   - Modify `mintPrice` in contract constructor
   - Adjust `maxSupply` limit
   - Change NFT name and symbol

2. **Frontend Styling:**
   - Update colors in `tailwind.config.js`
   - Modify components in `app/components/`
   - Customize global styles in `app/globals.css`

## Deployment to Production

### Frontend Deployment (Vercel)

1. **Build the application:**
```bash
npm run build
```

2. **Deploy to Vercel:**
```bash
npx vercel --prod
```

3. **Set environment variables** in Vercel dashboard

### Contract Deployment (Mainnet)

1. **Update network configuration** for mainnet
2. **Deploy with sufficient gas:**
```bash
npm run deploy -- --network mainnet
```

3. **Verify contract:**
```bash
npx hardhat verify --network mainnet DEPLOYED_CONTRACT_ADDRESS "CONSTRUCTOR_ARGS"
```

## Security Considerations

- ✅ Use environment variables for sensitive data
- ✅ Never commit private keys to version control
- ✅ Test thoroughly on testnets before mainnet
- ✅ Implement proper access controls
- ✅ Use OpenZeppelin audited contracts
- ✅ Validate all user inputs
- ✅ Handle errors gracefully

## Troubleshooting

### Common Issues

1. **"Insufficient funds" error:**
   - Ensure wallet has enough ETH for gas + mint price
   - Check network (testnet vs mainnet)

2. **"Contract not deployed" error:**
   - Verify contract address in environment variables
   - Ensure contract is deployed on correct network

3. **Wallet connection issues:**
   - Check MetaMask network settings
   - Clear browser cache and cookies
   - Try different wallet or browser

4. **Transaction fails:**
   - Increase gas limit
   - Check contract requirements (price, supply)
   - Verify wallet has sufficient balance

### Getting Help

- Check browser console for detailed error messages
- Verify network and contract address
- Test with small amounts first
- Join our Discord for community support

## Contributing

1. Fork the repository
2. Create feature branch (`git checkout -b feature/amazing-feature`)
3. Commit changes (`git commit -m 'Add amazing feature'`)
4. Push to branch (`git push origin feature/amazing-feature`)
5. Open Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- OpenZeppelin for secure smart contract libraries
- RainbowKit for wallet connection infrastructure
- Hardhat for development environment
- Next.js team for the amazing framework
- Tailwind CSS for utility-first styling

---

**⚠️ Disclaimer:** This is educational software. Use at your own risk. Always test on testnets before deploying to mainnet. The developers are not responsible for any losses incurred.
