import sys

def xor_decrypt(data: bytes, key: bytes) -> bytes:
    return bytes([b ^ key[i % len(key)] for i, b in enumerate(data)])

def main():
    if len(sys.argv) != 2:
        print("Usage: python decrypt_pf.py <file.pf>")
        return

    file_path = sys.argv[1]
    key = b"X8z!aP@9dL#kR2q$V1c*M7e&T^bW0nGh"

    with open(file_path, "rb") as f:
        encrypted_data = f.read()

    decrypted_data = xor_decrypt(encrypted_data, key)
    print(decrypted_data.decode(errors="replace"))

if __name__ == "__main__":
    main()
