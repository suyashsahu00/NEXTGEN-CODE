'use client';

import { useState } from 'react';
import { ConnectButton } from '@rainbow-me/rainbowkit';
import { useAccount } from 'wagmi';
import { Sparkles, Zap, Shield, Globe, Upload, Loader2, ExternalLink, CheckCircle } from 'lucide-react';

export default function Home() {
  const { isConnected } = useAccount();
  const [isLoading, setIsLoading] = useState(false);
  const [mintedNFT, setMintedNFT] = useState<{
    tokenId: string;
    txHash: string;
    name: string;
  } | null>(null);

  return (
    <div className="min-h-screen">
      {/* Header */}
      <header className="bg-white/80 backdrop-blur-sm border-b border-gray-200 sticky top-0 z-50">
        <div className="container mx-auto px-4 py-4">
          <div className="flex items-center justify-between">
            <div className="flex items-center space-x-2">
              <div className="bg-primary-600 p-2 rounded-lg">
                <Sparkles className="w-6 h-6 text-white" />
              </div>
              <div>
                <h1 className="text-xl font-bold text-gray-900">NFT Minter</h1>
                <p className="text-xs text-gray-500">Create • Own • Trade</p>
              </div>
            </div>
            
            <nav className="hidden md:flex items-center space-x-6">
              <a href="#" className="text-gray-600 hover:text-primary-600 transition-colors">
                Gallery
              </a>
              <a href="#" className="text-gray-600 hover:text-primary-600 transition-colors">
                About
              </a>
              <a href="#" className="text-gray-600 hover:text-primary-600 transition-colors">
                FAQ
              </a>
            </nav>
            
            <div className="flex items-center space-x-4">
              <ConnectButton />
            </div>
          </div>
        </div>
      </header>

      <main className="container mx-auto px-4 py-8">
        {/* Hero Section */}
        <div className="text-center mb-12">
          <h1 className="text-5xl font-bold gradient-text mb-6">
            Create Your Own NFTs
          </h1>
          <p className="text-xl text-gray-600 mb-8 max-w-2xl mx-auto">
            Mint unique digital assets on the blockchain. Connect your wallet, upload your art,
            and create NFTs that are truly yours.
          </p>
          
          {!isConnected && (
            <div className="mb-8">
              <ConnectButton />
            </div>
          )}
        </div>

        {/* Features Section */}
        <div className="grid md:grid-cols-4 gap-6 mb-12">
          <div className="text-center p-6">
            <div className="bg-primary-100 w-16 h-16 rounded-full flex items-center justify-center mx-auto mb-4">
              <Sparkles className="w-8 h-8 text-primary-600" />
            </div>
            <h3 className="font-semibold mb-2">Easy Minting</h3>
            <p className="text-gray-600 text-sm">Simple interface for creating NFTs</p>
          </div>
          
          <div className="text-center p-6">
            <div className="bg-primary-100 w-16 h-16 rounded-full flex items-center justify-center mx-auto mb-4">
              <Zap className="w-8 h-8 text-primary-600" />
            </div>
            <h3 className="font-semibold mb-2">Fast & Secure</h3>
            <p className="text-gray-600 text-sm">Built on Ethereum blockchain</p>
          </div>
          
          <div className="text-center p-6">
            <div className="bg-primary-100 w-16 h-16 rounded-full flex items-center justify-center mx-auto mb-4">
              <Shield className="w-8 h-8 text-primary-600" />
            </div>
            <h3 className="font-semibold mb-2">Ownership</h3>
            <p className="text-gray-600 text-sm">True digital ownership</p>
          </div>
          
          <div className="text-center p-6">
            <div className="bg-primary-100 w-16 h-16 rounded-full flex items-center justify-center mx-auto mb-4">
              <Globe className="w-8 h-8 text-primary-600" />
            </div>
            <h3 className="font-semibold mb-2">Global Market</h3>
            <p className="text-gray-600 text-sm">Trade on any NFT marketplace</p>
          </div>
        </div>

        {/* Minting Form */}
        {isConnected ? (
          <div className="max-w-2xl mx-auto">
            <div className="card">
              <h2 className="text-2xl font-bold mb-6">Mint Your NFT</h2>
              
              {mintedNFT ? (
                <div className="text-center py-8">
                  <CheckCircle className="w-16 h-16 text-green-500 mx-auto mb-4" />
                  <h3 className="text-xl font-bold mb-2">NFT Minted Successfully!</h3>
                  <p className="text-gray-600 mb-4">
                    Your NFT "{mintedNFT.name}" has been minted with Token ID: {mintedNFT.tokenId}
                  </p>
                  <div className="flex justify-center space-x-4">
                    <a
                      href={`https://sepolia.etherscan.io/tx/${mintedNFT.txHash}`}
                      target="_blank"
                      rel="noopener noreferrer"
                      className="btn-primary inline-flex items-center space-x-2"
                    >
                      <ExternalLink className="w-4 h-4" />
                      <span>View on Etherscan</span>
                    </a>
                    <button
                      onClick={() => setMintedNFT(null)}
                      className="btn-secondary"
                    >
                      Mint Another
                    </button>
                  </div>
                </div>
              ) : (
                <form className="space-y-6">
                  <div>
                    <label className="block text-sm font-medium text-gray-700 mb-2">
                      NFT Name
                    </label>
                    <input
                      type="text"
                      placeholder="Enter NFT name"
                      className="input-field"
                      required
                    />
                  </div>
                  
                  <div>
                    <label className="block text-sm font-medium text-gray-700 mb-2">
                      Description
                    </label>
                    <textarea
                      placeholder="Describe your NFT"
                      rows={4}
                      className="input-field resize-none"
                      required
                    />
                  </div>
                  
                  <div>
                    <label className="block text-sm font-medium text-gray-700 mb-2">
                      Upload Image
                    </label>
                    <div className="border-2 border-dashed border-gray-300 rounded-lg p-8 text-center hover:border-primary-400 transition-colors">
                      <Upload className="w-12 h-12 text-gray-400 mx-auto mb-4" />
                      <p className="text-gray-600 mb-2">Click to upload or drag and drop</p>
                      <p className="text-sm text-gray-500">PNG, JPG, GIF up to 10MB</p>
                      <input
                        type="file"
                        accept="image/*"
                        className="hidden"
                      />
                    </div>
                  </div>
                  
                  <div className="bg-gray-50 rounded-lg p-4">
                    <div className="flex justify-between items-center mb-2">
                      <span className="text-sm font-medium text-gray-700">Mint Price:</span>
                      <span className="text-sm font-bold">0.001 ETH</span>
                    </div>
                    <div className="flex justify-between items-center">
                      <span className="text-sm font-medium text-gray-700">Gas Fee:</span>
                      <span className="text-sm text-gray-600">~0.002 ETH</span>
                    </div>
                  </div>
                  
                  <button
                    type="submit"
                    disabled={isLoading}
                    className="w-full btn-primary flex items-center justify-center space-x-2"
                  >
                    {isLoading ? (
                      <>
                        <Loader2 className="w-4 h-4 animate-spin" />
                        <span>Minting...</span>
                      </>
                    ) : (
                      <span>Mint NFT</span>
                    )}
                  </button>
                </form>
              )}
            </div>
          </div>
        ) : (
          <div className="text-center py-12">
            <div className="card max-w-md mx-auto">
              <h2 className="text-2xl font-bold mb-4">Connect Your Wallet</h2>
              <p className="text-gray-600 mb-6">
                To start minting NFTs, please connect your wallet first.
              </p>
              <ConnectButton />
            </div>
          </div>
        )}
      </main>

      {/* Footer */}
      <footer className="bg-gray-900 text-white py-12 mt-20">
        <div className="container mx-auto px-4">
          <div className="grid md:grid-cols-4 gap-8">
            <div className="col-span-2">
              <h3 className="text-xl font-bold mb-4">NFT Minter</h3>
              <p className="text-gray-400 mb-4 max-w-md">
                A decentralized platform for creating and minting NFTs on the Ethereum blockchain.
                Own your digital art and trade on any marketplace.
              </p>
            </div>
            
            <div>
              <h4 className="font-semibold mb-4">Resources</h4>
              <ul className="space-y-2 text-gray-400">
                <li><a href="#" className="hover:text-white transition-colors">Documentation</a></li>
                <li><a href="#" className="hover:text-white transition-colors">Smart Contract</a></li>
                <li><a href="#" className="hover:text-white transition-colors">API Reference</a></li>
                <li><a href="#" className="hover:text-white transition-colors">Support</a></li>
              </ul>
            </div>
            
            <div>
              <h4 className="font-semibold mb-4">Community</h4>
              <ul className="space-y-2 text-gray-400">
                <li><a href="#" className="hover:text-white transition-colors">Discord</a></li>
                <li><a href="#" className="hover:text-white transition-colors">Telegram</a></li>
                <li><a href="#" className="hover:text-white transition-colors">Reddit</a></li>
                <li><a href="#" className="hover:text-white transition-colors">Blog</a></li>
              </ul>
            </div>
          </div>
          
          <div className="border-t border-gray-800 mt-8 pt-8 text-center text-gray-400">
            <p>&copy; 2024 NFT Minter. All rights reserved.</p>
          </div>
        </div>
      </footer>
    </div>
  );
}
