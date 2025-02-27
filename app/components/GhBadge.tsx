export default function GhBadge(props: { name: string, className?: string }) {
  const { name, className } = props

  return <a className={`${className} inline-flex items-center gap-1 hover:opacity-80`} href={`https://github.com/${name}`} target="_blank" rel="noreferrer">
    <img className="avatar rounded-full h-5" src={`https://wsrv.nl/?url=github.com/${name}.png%3fsize=96`} alt="" />
    {name}</a>
}